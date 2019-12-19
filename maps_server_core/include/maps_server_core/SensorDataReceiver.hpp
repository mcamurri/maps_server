#ifndef _maps_SensorDataReceiver_hpp_
#define _maps_SensorDataReceiver_hpp_

#include <string>
#include <memory>

namespace maps {

struct PointSet;
class LidarScan;

class SensorDataReceiver {
public:
  enum SensorType {
    SensorTypePlanarLidar,
    SensorTypePointCloud
  };

  struct SensorData {
    std::shared_ptr<PointSet> mPointSet;
    std::shared_ptr<LidarScan> mScan;
    SensorType mSensorType;
    std::string mChannel;
  };

public:
  SensorDataReceiver();
  ~SensorDataReceiver();

  virtual bool addChannel(const std::string& iSensorChannel,
                  const SensorType iSensorType,
                  const std::string& iTransformFrom,
                  const std::string& iTransformTo);
  virtual void clearChannels();
  virtual bool removeChannel(const std::string& iSensorChannel);

  virtual void setMaxBufferSize(const int iSize);
  virtual bool pop(SensorData& oData, const bool iNeedPose=true);
  virtual bool waitForData(SensorData& oData, const bool iNeedPose=true);
  virtual void unblock();

  virtual bool start();
  virtual bool stop();

protected:
  struct Helper;
  std::shared_ptr<Helper> mHelper;
};

}

#endif
