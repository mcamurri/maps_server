add_definitions(-std=c++1y -Wall)
set(MODULE_NAME plane-seg)

find_package(PkgConfig REQUIRED)
pkg_check_modules(PCL_IO pcl_io-1.7)
if(PCL_IO_FOUND)
  message("---- PCL IO was found\n")
  set(REQ_PKGS  pcl_io-1.7  pcl_surface-1.7 pcl_segmentation-1.7)
endif()

pkg_check_modules(PCL_IO_1_8 pcl_io-1.8)
if(PCL_IO_1_8_FOUND)
  message("---- PCL IO_1_8 was found\n")
  set(REQ_PKGS  pcl_io-1.8  pcl_surface-1.8 pcl_segmentation-1.8)
endif()

if(NOT PCL_IO_FOUND AND NOT PCL_IO_1_8_FOUND)
  message("---- PCL NOT FOUND. Not building maps_server")
  return()
endif()

# create library
set(LIB_NAME ${MODULE_NAME})
set(REQUIRED_PACKAGES
  eigen3
  ${REQ_PKGS}
)
add_library(${LIB_NAME} SHARED
  PlaneFitter.cpp
  RobustNormalEstimator.cpp
  IncrementalPlaneEstimator.cpp
  PlaneSegmenter.cpp
  RectangleFitter.cpp
  BlockFitter.cpp
)
pods_install_headers(
  Types.hpp
  PlaneFitter.hpp
  RobustNormalEstimator.hpp
  IncrementalPlaneEstimator.hpp
  PlaneSegmenter.hpp
  RectangleFitter.hpp
  BlockFitter.hpp
  DESTINATION ${LIB_NAME}
)
pods_install_libraries(${LIB_NAME})
pods_use_pkg_config_packages(${LIB_NAME} ${REQUIRED_PACKAGES})
pods_install_pkg_config_file(${LIB_NAME}
    CFLAGS -std=c++0x -Wall
    LIBS -l${LIB_NAME}
    REQUIRES ${REQUIRED_PACKAGES}
    VERSION 0.0.1)

# standalone lcm-based block fitter
#set(APP_NAME drc-block-fitter)
#add_executable(${APP_NAME} block-fitter.cpp)
#target_link_libraries(${APP_NAME} boost_system pthread)
#pods_use_pkg_config_packages(${APP_NAME} ${LIB_NAME} maps bot2-lcmgl-client)
#pods_install_executables(${APP_NAME})


# test program
set(APP_NAME ${MODULE_NAME}-test)
add_executable(${APP_NAME} ${APP_NAME}.cpp)
target_link_libraries(${APP_NAME} boost_system)
pods_use_pkg_config_packages(${APP_NAME} ${LIB_NAME})
pods_install_executables(${APP_NAME})


# fit single block
set(APP_NAME ${MODULE_NAME}-test2)
add_executable(${APP_NAME} ${APP_NAME}.cpp)
target_link_libraries(${APP_NAME} boost_system)
pods_use_pkg_config_packages(${APP_NAME} ${LIB_NAME})
pods_install_executables(${APP_NAME})
