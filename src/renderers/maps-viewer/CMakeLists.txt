find_package(PkgConfig REQUIRED)
pkg_check_modules(BOT2_VIS bot2-vis)
if(NOT BOT2_VIS_FOUND)
    message("bot2-vis not found.  Not building libbot2 renderer")
    return()
endif(NOT BOT2_VIS_FOUND)

#add_definitions(-Wall -std=gnu99)

link_libraries(boost_thread)

add_executable(maps-viewer maps_viewer.cpp)
pods_use_pkg_config_packages(maps-viewer bot2-vis 
  lcm
  bot2-frames-renderers
  maps-renderer

#  bot2-frames-renderers-pronto
#  octomap-renderer
#  occ-map-renderers
#  laser-util-renderer
#  bot2-lcmgl-renderer
#  collections_renderer
#  mav-state-est-renderers
#  renderer_rs
#  lcmtypes_occ-map

  path-util)

pods_install_executables(maps-viewer)




