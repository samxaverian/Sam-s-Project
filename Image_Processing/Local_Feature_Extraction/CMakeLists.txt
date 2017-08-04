cmake_minimum_required(VERSION 2.6)
cmake_policy(SET CMP0012 NEW)
project(rgb2hue)
find_package(OpenCV 3.0.0 REQUIRED)
message("OpenCV version :${OpenCV_VERSION}")
include_directories(${OpenCV_INCLUDE_DIR})
link_directories(${OpenCV_LIB_DIR})
SET(SRC main.cpp)
add_executable(hue rgb2hue.cpp)
target_link_libraries(hue ${OpenCV_LIBS})

 
 
 
