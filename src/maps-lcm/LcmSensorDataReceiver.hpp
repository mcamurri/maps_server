#ifndef _maps_LcmSensorDataReceiver_hpp_
#define _maps_LcmSensorDataReceiver_hpp_

#include <string>
#include <memory>

#include <maps/SensorDataReceiver.hpp>

namespace maps {

struct PointSet;
class LidarScan;
class BotWrapper;

class LcmSensorDataReceiver: public SensorDataReceiver {
public:
//  enum SensorType {
//    SensorTypePlanarLidar,
//    SensorTypePointCloud
//  };

//  struct SensorData {
//    std::shared_ptr<PointSet> mPointSet;
//    std::shared_ptr<LidarScan> mScan;
//    SensorType mSensorType;
//    std::string mChannel;
//  };

public:
  LcmSensorDataReceiver();
  ~LcmSensorDataReceiver();

  void setBotWrapper(const std::shared_ptr<BotWrapper>& iWrapper);
  bool addChannel(const std::string& iSensorChannel,
                  const SensorType iSensorType,
                  const std::string& iTransformFrom,
                  const std::string& iTransformTo);
  void clearChannels();
  bool removeChannel(const std::string& iSensorChannel);

  void setMaxBufferSize(const int iSize);
  bool pop(SensorData& oData, const bool iNeedPose=true);
  bool waitForData(SensorData& oData, const bool iNeedPose=true);
  void unblock();

  bool start();
  bool stop();

protected:
  struct Helper;
  std::shared_ptr<Helper> mHelper;
};

}

#endif
