cmake_minimum_required(VERSION 2.6.0)

# pull in the pods macros. See cmake/pods.cmake for documentation
set(POD_NAME maps-server)
include(cmake/pods.cmake)

include(cmake/lcmtypes.cmake)
lcmtypes_build()

add_subdirectory(src/maps_utils)

# main maps library (no application)
add_subdirectory(src/libmaps)

# library: minimal version of the above
#add_subdirectory(src/libmaps-mini)
# library: used for filling in cell in height maps
#add_subdirectory(src/terrain-map)


add_subdirectory(src/maps_lcm)


# applications using libmaps
add_subdirectory(src/server)
add_subdirectory(src/apps)

# misc utils
add_subdirectory(src/utils)

# Maps GTK renderer works as of Feb 2017
#add_subdirectory(src/renderers)
