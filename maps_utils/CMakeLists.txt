cmake_minimum_required(VERSION 2.6.0)

# pull in the pods macros. See cmake/pods.cmake for documentation
set(POD_NAME maps_utils)
include(cmake/pods.cmake)

add_subdirectory(src/maps_utils)