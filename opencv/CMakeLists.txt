cmake_minimum_required(VERSION 2.8)
project( process )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( process src/process.cpp)
add_executable( process_invert src/process_invert.cpp)
add_executable( basic src/basic.cpp)
add_executable( viz src/viz.cpp)
target_link_libraries( process ${OpenCV_LIBS} )
target_link_libraries( process_invert ${OpenCV_LIBS} )
target_link_libraries( basic ${OpenCV_LIBS} )
target_link_libraries( viz ${OpenCV_LIBS} )


set(CMAKE_BUILD_TYPE RelWithDebInfo)
