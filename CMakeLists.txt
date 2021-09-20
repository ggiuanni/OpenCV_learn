cmake_minimum_required(VERSION 3.18.4)
project(OpenCV_Learn)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV 4.0.0 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIB_DIR})

add_subdirectory(include/read_write_img)
add_subdirectory(include/read_video)

add_executable(${PROJECT_NAME}
	src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME}
	ReadWriteImg
	ReadVideo)
