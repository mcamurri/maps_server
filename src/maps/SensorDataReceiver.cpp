#include "SensorDataReceiver.hpp"

#include <unordered_map>
#include <list>
#include <thread>
#include <mutex>

#include "Types.hpp"
#include "LidarScan.hpp"
#include "ThreadSafeQueue.hpp"


using namespace maps;


SensorDataReceiver::
SensorDataReceiver() {
}

SensorDataReceiver::
~SensorDataReceiver() {
  clearChannels();
}

bool SensorDataReceiver::
addChannel(const std::string& iSensorChannel,
           const SensorType iSensorType,
           const std::string& iTransformFrom,
           const std::string& iTransformTo) {
  exit(-1);
  return true;
}

void SensorDataReceiver::
clearChannels() {
  exit(-1);
}

bool SensorDataReceiver::
removeChannel(const std::string& iSensorChannel) {
  exit(-1);
  return true;
}

void SensorDataReceiver::
setMaxBufferSize(const int iSize) {
  exit(-1);
}

bool SensorDataReceiver::
pop(SensorData& oData, const bool iNeedPose) {
  exit(-1);
   return true;
}

bool SensorDataReceiver::
waitForData(SensorData& oData, const bool iNeedPose) {
  exit(-1);
  return true;
}

void SensorDataReceiver::
unblock() {
  exit(-1);
}

bool SensorDataReceiver::
start() {
  exit(-1);
  return true;
}

bool SensorDataReceiver::
stop() {
  exit(-1);
  return true;
}
