add_library(ReadVideo
	src/ReadVideo.cpp)

target_include_directories(ReadVideo PUBLIC include)

target_link_libraries(ReadWriteImg ${OpenCV_LIBS})
