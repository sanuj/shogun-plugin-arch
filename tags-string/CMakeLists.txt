CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(ShogunPlugArch)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# The version number.
SET(ShogunPlugArch_VERSION_MAJOR 0)
SET(ShogunPlugArch_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
CONFIGURE_FILE(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}")
INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}")

# add a subdirectory
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(tests)
