# Create a shared library
add_library(maps SHARED
  LidarUtils.cpp
  DataBlob.cpp
  Utils.cpp
  PointDataBuffer.cpp
  VoxelGrid.cpp
  DepthImage.cpp
  LidarScan.cpp
  SensorDataReceiver.cpp
  ViewBase.cpp
  PointCloudView.cpp
  OctreeView.cpp
  DepthImageView.cpp
  VoxelGridView.cpp
  ScanBundleView.cpp
  LocalMap.cpp
  MapManager.cpp
  Collector.cpp
)

# make the header public
# install it to include/maps
pods_install_headers(
  LidarUtils.hpp
  PointerUtils.hpp
  ThreadSafeQueue.hpp
  RansacGeneric.hpp
  PointConvert.hpp
  Types.hpp
  ThreadSafeQueue.hpp
  RansacGeneric.hpp
  ObjectPool.hpp
  DataBlob.hpp
  Utils.hpp
  PointDataBuffer.hpp
  VoxelGrid.hpp
  DepthImage.hpp
  LidarScan.hpp
  SensorDataReceiver.hpp
  ViewBase.hpp
  PointCloudView.hpp
  OctreeView.hpp
  DepthImageView.hpp
  VoxelGridView.hpp
  ScanBundleView.hpp
  LocalMap.hpp
  MapManager.hpp
  Collector.hpp
  DESTINATION maps
)

# make the library public
pods_install_libraries(maps)

find_package(PkgConfig REQUIRED)
pkg_check_modules(PCL_IO pcl_io-1.7)
if(PCL_IO_FOUND)
  message("---- PCL IO was found\n")
  set(REQ_PKGS  pcl_common-1.7  pcl_filters-1.7  pcl_features-1.7  pcl_io-1.7  pcl_surface-1.7)
endif()

pkg_check_modules(PCL_IO_1_8 pcl_io-1.8)
if(PCL_IO_1_8_FOUND)
  message("---- PCL IO_1_8 was found\n")
  set(REQ_PKGS  pcl_common-1.8  pcl_filters-1.8  pcl_features-1.8  pcl_io-1.8  pcl_surface-1.8)
endif()

if(NOT PCL_IO_FOUND AND NOT PCL_IO_1_8_FOUND)
  message("---- PCL NOT FOUND. Not building maps_server")
  return()
endif()



set(REQUIRED_PACKAGES
  eigen3
  ${REQ_PKGS}
  octomap
  glib-2.0
  zlib
)
pods_use_pkg_config_packages(maps ${REQUIRED_PACKAGES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wno-deprecated-declarations -Wno-attributes -Wreturn-type -Wuninitialized -Wunused-variable")

# create a pkg-config file for the library, to make it easier for other
# software to use.
pods_install_pkg_config_file(maps
    CFLAGS -std=c++0x -Wno-deprecated-declarations
    LIBS -lmaps
    REQUIRES ${REQUIRED_PACKAGES}
    VERSION 0.0.1)
