cmake_minimum_required(VERSION 2.8)
set(OpenCV_DIR "/home/lingkang/Documents/opencv-3.1.0/build")
project(optical_flow_tracker)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pthread")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
find_package(Threads REQUIRED)
add_definitions(-std=c++11)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/mtcnn-ncnn/mtcnn/build)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/mtcnn-ncnn/mtcnn)

#add_library(detntrack lk_tracker.cpp munkres.cpp det_and_track.cpp)
#target_link_libraries(detntrack mtcnn ${OpenCV_LIBS})

add_executable( multi_thread_det_and_track main.cpp lk_tracker.cpp munkres.cpp det_and_track.cpp)
target_link_libraries( multi_thread_det_and_track mtcnn ${OpenCV_LIBS})
