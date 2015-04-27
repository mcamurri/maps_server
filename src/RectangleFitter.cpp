#include "RectangleFitter.hpp"

#include <pcl/surface/convex_hull.h>
#include <pcl/common/transforms.h>
#include <pcl/common/common.h>

using namespace planeseg;

RectangleFitter::
RectangleFitter() {
  setDimensions(Eigen::Vector2f(0,0));
}

void RectangleFitter::
setDimensions(const Eigen::Vector2f& iSize) {
  mRectangleSize = iSize;
}

void RectangleFitter::
setData(const MatrixX3f& iPoints, const Eigen::Vector4f& iPlane) {
  mPoints = iPoints;
  mPlane = iPlane;
}

RectangleFitter::Result
RectangleFitter::go() {
  // project points onto plane
  Eigen::VectorXf distances = (mPoints*mPlane.head<3>()).array() + mPlane[3];
  MatrixX3f points = mPoints - distances*mPlane.head<3>().transpose();

  // copy points into cloud
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud
    (new pcl::PointCloud<pcl::PointXYZ>());
  cloud->resize(points.rows());
  for (int i = 0; i < (int)points.rows(); ++i) {
    cloud->points[i].getVector3fMap() = points.row(i);
  }

  // compute convex hull
  pcl::ConvexHull<pcl::PointXYZ> chull;
  pcl::PointCloud<pcl::PointXYZ> hull;
  chull.setInputCloud(cloud);
  chull.reconstruct(hull);

  // convenience structure for evaluating each candidate
  struct Entry {
    int mEdgeIndex;
    Eigen::Vector3f mPointMin;
    Eigen::Vector3f mPointMax;
    Eigen::Isometry3f mTransform;
    float mArea;
    Entry() : mEdgeIndex(-1), mPointMin(0,0,0), mPointMax(0,0,0),
              mTransform(Eigen::Isometry3f::Identity()), mArea(0) {}
  };
  Entry bestEntry;
  float bestScore = 1e10;

  // are we using prior dimensions?
  bool usePriorSize = (mRectangleSize.norm() > 1e-6);

  // loop over and evaluate each convex hull edge
  int n = hull.size();
  for (int i = 0; i < n; ++i) {

    // get edge endpoints
    Eigen::Vector3f p0 = hull.points[i].getVector3fMap();
    Eigen::Vector3f p1 = hull.points[(i+1)%n].getVector3fMap();

    // check for repeated point (thus invalid edge direction)
    if ((p1-p0).norm() < 1e-6) continue;

    // transform points to plane parallel to z=0
    pcl::PointCloud<pcl::PointXYZ> flatCloud;
    Eigen::Isometry3f transform = Eigen::Isometry3f::Identity();
    Eigen::Matrix3f rot;
    rot.col(2) = mPlane.head<3>();
    rot.col(0) = (p1-p0).normalized();
    rot.col(1) = rot.col(2).cross(rot.col(0)).normalized();
    transform.translation() = p0;
    transform.linear() = rot;
    transform = transform.inverse();
    pcl::transformPointCloud(hull, flatCloud,
                             Eigen::Affine3f(transform.matrix()));

    // find extents
    Eigen::Vector4f minPoint, maxPoint;
    pcl::getMinMax3D(flatCloud, minPoint, maxPoint);

    // create entry for this edge
    Entry entry;
    entry.mEdgeIndex = i;
    entry.mPointMin << minPoint[0], minPoint[1], 0;
    entry.mPointMax << maxPoint[0], maxPoint[1], 0;
    entry.mArea = (entry.mPointMax-entry.mPointMin).head<2>().norm();
    entry.mTransform = transform;

    // compute score
    float score;

    // score is closest area to prior size area
    // TODO: could score based on how much of the convex hull is near the perimeter
    if (usePriorSize) {
      Eigen::Vector2f size = (entry.mPointMax-entry.mPointMin).head<2>();
      score = (size-mRectangleSize).norm();
    }

    // score is simply minimum area
    else {
      score = entry.mArea;
    }

    // replace best score
    if (score < bestScore) {
      bestEntry = entry;
      bestScore = score;
    }
  }

  // construct rectangle corners
  Eigen::Vector3f center = 0.5*(bestEntry.mPointMin + bestEntry.mPointMax);
  Eigen::Vector3f size = bestEntry.mPointMax-bestEntry.mPointMin;
  if (usePriorSize) size.head<2>() = mRectangleSize;
  Eigen::Vector3f p0(center[0]-size[0]/2, center[1]-size[1]/2, 0);
  Eigen::Vector3f p1(center[0]-size[0]/2, center[1]+size[1]/2, 0);
  Eigen::Vector3f p2(center[0]+size[0]/2, center[1]+size[1]/2, 0);
  Eigen::Vector3f p3(center[0]+size[0]/2, center[1]-size[1]/2, 0);

  // fill result structure
  Result result;
  result.mPlane = mPlane;
  result.mPolygon = { p0, p1, p2, p3 };
  Eigen::Isometry3f transformInv = bestEntry.mTransform.inverse();
  result.mPose = transformInv;
  result.mPose.translation() = transformInv*center;
  for (auto& pt : result.mPolygon) pt = transformInv*pt;
  for (auto& pt : hull.points) {
    result.mConvexHull.push_back(pt.getVector3fMap());
  }
  return result;
}
