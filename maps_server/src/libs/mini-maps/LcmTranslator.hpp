#ifndef _maps_LcmTranslator_hpp_
#define _maps_LcmTranslator_hpp_

namespace maps {
  class request_t;
  class blob_t;
  class image_t;
}

#include "ViewBase.hpp"

namespace maps {

class DataBlob;
class DepthImageView;

class LcmTranslator {
public:

  // for view request
  static bool toLcm(const ViewBase::Spec& iSpec, maps::request_t& oMessage);
  static bool fromLcm(const maps::request_t& iMessage,
                      ViewBase::Spec& oSpec);

  // for data blobs
  static bool toLcm(const maps::DataBlob& iBlob, maps::blob_t& oMessage);
  static bool fromLcm(const maps::blob_t& iMessage, maps::DataBlob& oBlob);

  // for depth image
  static bool toLcm(const DepthImageView& iView, maps::image_t& oMessage,
                    const float iQuantMax=-1, const bool iCompress=true);
  static bool fromLcm(const maps::image_t& iMessage, DepthImageView& oView);
};

}

#endif
