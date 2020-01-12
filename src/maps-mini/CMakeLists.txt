cmake_minimum_required(VERSION 3.0)
project(maps_mini)

find_package(Eigen3)
include_directories(${EIGEN3_INCLUDE_DIRS})

find_package(catkin REQUIRED COMPONENTS maps_server_core maps_server_msgs)
include_directories(${catkin_INCLUDE_DIRS})

set(LIB_NAME ${PROJECT_NAME})

# Create a shared library
add_library(${LIB_NAME} SHARED ViewBase.cpp
                               Utils.cpp
			       # LcmTranslator.cpp
                               DepthImage.cpp
                               DepthImageView.cpp
			       #ViewClient.cpp
			       )


