cmake_minimum_required(VERSION 2.6.0)

# pull in the pods macros. See cmake/pods.cmake for documentation
set(POD_NAME maps-server)
include(cmake/pods.cmake)

include(cmake/lcmtypes.cmake)
lcmtypes_build()

# non-lcm tools
#add_subdirectory(src/maps_utils)

# main maps library (no application)
add_subdirectory(src/libmaps)

# some lcm tools used in lcm
add_subdirectory(src/maps_lcm_utils)

# library: minimal version of the above
add_subdirectory(src/libmaps-mini)


# maps library specific to lcm
add_subdirectory(src/maps_lcm)


# library: used for filling in cell in height maps
add_subdirectory(src/terrain-map)




# applications using libmaps
add_subdirectory(src/server)
add_subdirectory(src/apps)

# misc utils
add_subdirectory(src/utils)

# Maps GTK renderer works as of Feb 2017
# add_subdirectory(src/renderers)
