cmake_minimum_required(VERSION 2.8)
project( process )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( process src/process.cpp)
add_executable( process_invert src/process_invert.cpp)
add_executable( input_output src/input_output.cpp)
target_link_libraries( process ${OpenCV_LIBS} )
target_link_libraries( process_invert ${OpenCV_LIBS} )
target_link_libraries( input_output ${OpenCV_LIBS} )


set(CMAKE_BUILD_TYPE RelWithDebInfo)
