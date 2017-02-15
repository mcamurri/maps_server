#ifndef _maps_LcmTranslator_hpp_
#define _maps_LcmTranslator_hpp_

namespace maps {
  class request_t;
  class params_t;
  class blob_t;
  class cloud_t;
  class octree_t;
  class image_t;
  class scans_t;
  class scan_t;
}

#include "LocalMap.hpp"
#include "ViewBase.hpp"

namespace maps {

class DataBlob;
class PointCloudView;
class OctreeView;
class DepthImageView;
class ScanBundleView;
class LidarScan;

class LcmTranslator {
public:

  // for map specification
  static bool toLcm(const LocalMap::Spec& iSpec, maps::params_t& oMessage);
  static bool fromLcm(const maps::params_t& iMessage, LocalMap::Spec& oSpec);

  // for view request
  static bool toLcm(const ViewBase::Spec& iSpec, maps::request_t& oMessage);
  static bool fromLcm(const maps::request_t& iMessage,
                      ViewBase::Spec& oSpec);

  // for data blobs
  static bool toLcm(const maps::DataBlob& iBlob, maps::blob_t& oMessage);
  static bool fromLcm(const maps::blob_t& iMessage, maps::DataBlob& oBlob);

  // for point cloud
  static bool toLcm(const PointCloudView& iView, maps::cloud_t& oMessage,
                    const float iQuantMax=-1, const bool iCompress=true);
  static bool fromLcm(const maps::cloud_t& iMessage, PointCloudView& oView);

  // for octree
  static bool toLcm(const OctreeView& iView, maps::octree_t& oMessage);
  static bool fromLcm(const maps::octree_t& iMessage, OctreeView& oView);

  // for depth image
  static bool toLcm(const DepthImageView& iView, maps::image_t& oMessage,
                    const float iQuantMax=-1, const bool iCompress=true);
  static bool fromLcm(const maps::image_t& iMessage, DepthImageView& oView);

  // for scan
  static bool toLcm(const LidarScan& iScan, maps::scan_t& oMessage,
                    const float iQuantMax=-1, const bool iCompress=true,
                    const bool iIncludeIntensities=false);
  static bool fromLcm(const maps::scan_t& iMessage, LidarScan& oScan);

  // for scan bundle
  static bool toLcm(const ScanBundleView& iView, maps::scans_t& oMessage,
                    const float iQuantMax=-1, const bool iCompress=true,
                    const bool iIncludeIntensities=false);
  static bool fromLcm(const maps::scans_t& iMessage, ScanBundleView& oView);
};

}

#endif
