cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(heightmap_lcmgl)

add_executable(drc-gradmap-send gradmap_send.cpp)


add_executable(drc-write-maps-octree write_octomap.cpp  )
