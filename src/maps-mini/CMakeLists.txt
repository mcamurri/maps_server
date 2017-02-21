set(LIB_NAME "maps-mini")

# Create a shared library
add_library(${LIB_NAME} SHARED
  ViewBase.cpp
  DataBlob.cpp
  Utils.cpp
  LcmTranslator.cpp
  DepthImage.cpp
  DepthImageView.cpp
  ViewClient.cpp
)

# make the header public
# install it to include/maps
pods_install_headers(
  ViewBase.hpp
  DataBlob.hpp
  Utils.hpp
  LcmTranslator.hpp
  ViewClient.hpp
  DepthImage.hpp
  DepthImageView.hpp
  DESTINATION maps_mini
)

# make the library public
pods_install_libraries(${LIB_NAME})

set(REQUIRED_PACKAGES
  maps-lcm
  zlib
)
pods_use_pkg_config_packages(${LIB_NAME} ${REQUIRED_PACKAGES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wall")

# create a pkg-config file for the library, to make it easier for other
# software to use.
pods_install_pkg_config_file(${LIB_NAME}
    CFLAGS ${CMAKE_CXX_FLAGS}
    LIBS -l${LIB_NAME}
    REQUIRES ${REQUIRED_PACKAGES}
    VERSION 0.0.1)


add_executable(maps-mini-test TestMain.cpp)
pods_use_pkg_config_packages(maps-mini-test maps-mini)
pods_install_executables(maps-mini-test)
