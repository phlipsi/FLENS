cmake_minimum_required(VERSION 2.6)

# Tests whether LinAlg is a subproject of another project
#   CMAKE_SOURCE_DIR         : Directory, from which cmake was started
#   CMAKE_CURRENT_SOURCE_DIR : Directory, where this CMakeLists.txt is located
if (NOT ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}"))
  set(FLENS_IS_SUBPROJECT True)
else()
  set(FLENS_IS_SUBPROJECT False)
endif()

if (NOT FLENS_IS_SUBPROJECT)
  project(FLENS)
endif()

include_directories(.)
add_definitions(-std=c++11 -stdlib=libc++)

add_library(FLENS flens/debug/auxiliary/closurelog.cc flens/debug/auxiliary/closurelogstream.cc)
