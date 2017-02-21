cmake_minimum_required(VERSION 2.6.0)

# pull in the pods macros. See cmake/pods.cmake for documentation
set(POD_NAME maps)
find_package(PkgConfig)
pkg_check_modules(LCMTYPES_BOT2CORE lcmtypes_bot2-core)
include_directories(${LCMTYPES_BOT2CORE_INCLUDE_DIRS})
include(cmake/pods.cmake)

include(cmake/lcmtypes.cmake)
lcmtypes_build()

# main maps library (no application)
add_subdirectory(src/maps)

# maps library specific to lcm
add_subdirectory(src/maps-lcm)

# library: minimal version of the above
add_subdirectory(src/maps-mini)

# library: used for filling in cell in height maps
add_subdirectory(src/terrain-map)

# LCM applications using maps and maps_lcm
add_subdirectory(src/server)
add_subdirectory(src/apps)

# misc utils
add_subdirectory(src/utils)

add_subdirectory(src/plane-seg)

# Maps GTK renderer works as of Feb 2017
#add_subdirectory(src/renderers)
