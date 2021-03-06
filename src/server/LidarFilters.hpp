#include <maps/LocalMap.hpp>
#include <maps_lcm/BotWrapper.hpp>

#include <lcm/lcm-cpp.hpp>
#include <lcmtypes/maps/depth_settings_t.hpp>

namespace maps {

class TorsoFilter : public LocalMap::Filter {
public:
  TorsoFilter(const BotWrapper::Ptr& iBotWrapper);
  void operator()(maps::PointSet& ioPoints);

protected:
  BotWrapper::Ptr mBotWrapper;
};

class GroundFilter : public LocalMap::Filter {
public:
  GroundFilter(const BotWrapper::Ptr& iBotWrapper);
  void operator()(maps::PointSet& ioPoints);

  void onSettings(const lcm::ReceiveBuffer* iBuf,
                  const std::string& iChannel,
                  const maps::depth_settings_t* iMessage);

protected:
  BotWrapper::Ptr mBotWrapper;
  bool mActive;
};

}
