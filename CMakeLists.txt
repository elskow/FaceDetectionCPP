cmake_minimum_required(VERSION 3.25)
project(FaceDetection)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 20)

add_executable(FaceDetection main.cpp)

target_link_libraries(FaceDetection ${OpenCV_LIBS})
