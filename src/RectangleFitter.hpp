#ifndef _planeseg_RectangleFitter_hpp_
#define _planeseg_RectangleFitter_hpp_

#include "Types.hpp"

namespace planeseg {

class RectangleFitter {
public:
  struct Result {
    Eigen::Vector4f mPlane;
    std::vector<Eigen::Vector3f> mPolygon;
    std::vector<Eigen::Vector3f> mConvexHull;
    float mArea;
    float mConvexArea;
    Eigen::Isometry3f mPose;
  };

public:
  RectangleFitter();

  void setDimensions(const Eigen::Vector2f& iSize);
  void setData(const MatrixX3f& iPoints, const Eigen::Vector4f& iPlane);
  Result go();

protected:
  Eigen::Vector2f mRectangleSize;
  MatrixX3f mPoints;
  Eigen::Vector4f mPlane;
};

}

#endif
