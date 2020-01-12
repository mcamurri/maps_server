cmake_minimum_required(VERSION 2.8.3)
project(maps_server_core)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED)

find_package(PCL 1.8 REQUIRED COMPONENTS common filters features io surface)

find_package(Eigen3 REQUIRED)

find_package(octomap REQUIRED)


catkin_package(INCLUDE_DIRS include
               LIBRARIES maps
               CATKIN_DEPENDS 
               DEPENDS EIGEN3 OCTOMAP)

include_directories(include ${catkin_INCLUDE_DIRS})
include_directories(${PCL_INCLUDE_DIRS})
include_directories(${EIGEN3_INCLUDE_DIRS})
include_directories(${OCTOMAP_INCLUDE_DIRS})

add_library(maps SHARED src/LidarUtils.cpp
                        src/DataBlob.cpp
                        src/Utils.cpp
                        src/PointDataBuffer.cpp
                        src/VoxelGrid.cpp
                        src/DepthImage.cpp
                        src/LidarScan.cpp
                        src/SensorDataReceiver.cpp
                        src/ViewBase.cpp
                        src/PointCloudView.cpp
                        src/OctreeView.cpp
                        src/DepthImageView.cpp
                        src/VoxelGridView.cpp
                        src/ScanBundleView.cpp
                        src/LocalMap.cpp
                        src/MapManager.cpp
                        src/Collector.cpp
			src/DepthImage.cpp
			src/DepthImageView.cpp
			src/Utils.cpp
			src/ViewBase.cpp)

target_link_libraries(maps ${PCL_LIBRARIES})
add_dependencies(maps ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

install(TARGETS maps
        ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
        RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION})

install(DIRECTORY include/${PROJECT_NAME}/
        DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
        FILES_MATCHING PATTERN "*.h")

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_maps_server_core.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
