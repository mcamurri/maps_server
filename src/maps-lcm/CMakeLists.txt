# Create a shared library
add_library(maps-lcm SHARED
  Clock.cpp
  LcmWrapper.cpp
  BotWrapper.cpp
  LcmSensorDataReceiver.cpp
  LcmTranslator.cpp
  ViewClient.cpp
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(PCL_IO pcl_io-1.7)
if(PCL_IO_FOUND)
  message("---- PCL IO was found\n")
  set(REQ_PKGS  pcl_common-1.7 pcl_filters-1.7  pcl_features-1.7  pcl_io-1.7  pcl_surface-1.7)
endif()

pkg_check_modules(PCL_IO_1_8 pcl_io-1.8)
if(PCL_IO_1_8_FOUND)
  message("---- PCL IO_1_8 was found\n")
  set(REQ_PKGS  pcl_common-1.8 pcl_filters-1.8  pcl_features-1.8  pcl_io-1.8  pcl_surface-1.8)
endif()

if(NOT PCL_IO_FOUND AND NOT PCL_IO_1_8_FOUND)
  message("---- PCL NOT FOUND. Not building maps_server")
  return()
endif()


# make the header public
# install it to include/maps
pods_install_headers(
  Clock.hpp
  LcmWrapper.hpp
  BotWrapper.hpp
  LcmSensorDataReceiver.hpp
  LcmTranslator.hpp
  ViewClient.hpp
  DESTINATION maps_lcm
)

# make the library public
pods_install_libraries(maps-lcm)

set(REQUIRED_PACKAGES
  eigen3
  ${REQ_PKGS}
  octomap
  glib-2.0
  bot2-frames
  lcm
  zlib
  maps
)
pods_use_pkg_config_packages(maps-lcm ${REQUIRED_PACKAGES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wno-deprecated-declarations -Wno-attributes -Wreturn-type -Wuninitialized -Wunused-variable")

# create a pkg-config file for the library, to make it easier for other
# software to use.
pods_install_pkg_config_file(maps-lcm
    CFLAGS -std=c++0x -Wno-deprecated-declarations
    LIBS -lmaps-lcm
    REQUIRES ${REQUIRED_PACKAGES}
    VERSION 0.0.1)
