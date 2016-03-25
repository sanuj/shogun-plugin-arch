cmake_minimum_required (VERSION 3.1)
project (ShogunPlugArch)

# The version number.
set (ShogunPlugArch_VERSION_MAJOR 0)
set (ShogunPlugArch_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories ("${PROJECT_BINARY_DIR}")

# add a subdirectory
add_subdirectory (src)
