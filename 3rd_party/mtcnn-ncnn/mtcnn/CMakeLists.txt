#set(OpenCV_Install /Users/hongtaozhang/workspace/machine-learning/face_detect/opencv-master/install_loc)
#set(OpenCV_DIR ${OpenCV_Install}/share/OpenCV)
cmake_minimum_required(VERSION 2.8)

project(mtcnn)

set(CMAKE_BUILD_TYPE Release)

find_package( OpenCV REQUIRED )
#find_package(OpenCV REQUIRED core highgui imgproc)

if (NOT OpenCV_FOUND)
    message(FATAL_ERROR "opencv Not Found!")
else()
    message(STATUS "OpenCV_LIBS: ${OpenCV_LIBS}")
    message(STATUS "OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")
endif (NOT OpenCV_FOUND)

add_definitions(-std=c++11)

message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/../../build/src)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/../../build/src)

SET(NCNNLIB -Wl,--whole-archive ncnn -Wl,--no-whole-archive)

link_directories(
  ${OpenCV_Install}/lib
)
#add_executable(mtcnn mtcnn.cpp)
add_library(mtcnn SHARED object_detection.cpp mtcnn.cpp)
target_link_libraries(mtcnn ${NCNNLIB} ${OpenCV_LIBS})

set_property(TARGET mtcnn PROPERTY POSITION_INDEPENDENT_CODE ON)


