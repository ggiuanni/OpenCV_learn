add_library(ReadWriteImg
	src/ReadWriteImg.cpp)

target_include_directories(ReadWriteImg PUBLIC include)

target_link_libraries(ReadWriteImg ${OpenCV_LIBS})
