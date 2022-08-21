cmake_minimum_required(VERSION 3.16)

project(galaxy LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH})

find_package(PkgConfig)
find_package(Pixman)
find_package(Wayland 1.2 REQUIRED COMPONENTS Cursor Server OPTIONAL_COMPONENTS Egl)
find_package(WaylandProtocols)
find_package(WaylandScanner REQUIRED QUIET)
find_package(wlroots)

include_directories(
  ${PIXMAN_INCLUDE_DIR}
)

add_definitions(-DWLR_USE_UNSTABLE -DLIBWAYLIB_SERVER_LIBRARY)

add_subdirectory(src)