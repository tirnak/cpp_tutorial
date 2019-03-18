cmake_minimum_required(VERSION 2.8)
find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

add_executable(boost.o boost.cpp)
target_link_libraries( boost.o ${Boost_LIBRARIES} )

