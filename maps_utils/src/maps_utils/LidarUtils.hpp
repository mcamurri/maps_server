#ifndef _maps_LidarUtils_hpp_
#define _maps_LidarUtils_hpp_

#include <vector>
#include <Eigen/Geometry>

namespace maps {
class LidarUtils {
public:
  static bool
  interpolateScan(const std::vector<float>& iRanges,
                  const double iTheta0, const double iThetaStep,
                  const Eigen::Isometry3d& iPose0,
                  const Eigen::Isometry3d& iPose1,
                  std::vector<Eigen::Vector3f>& oPoints);
};
}

#endif
