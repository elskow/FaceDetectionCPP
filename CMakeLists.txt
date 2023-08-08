cmake_minimum_required(VERSION 3.20)
project(FaceDetection)

file(COPY haarcascade_frontalface_default.xml DESTINATION ${CMAKE_BINARY_DIR})

set(OpenCV_DIR "C:\\opencv\\build\\x64\\vc16\\lib")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 20)

add_executable(FaceDetection main.cpp)

target_link_libraries(FaceDetection ${OpenCV_LIBS})