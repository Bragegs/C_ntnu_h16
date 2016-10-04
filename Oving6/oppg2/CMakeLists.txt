cmake_minimum_required(VERSION 2.8)

project(oppg2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra -Wno-unused-parameter")

find_package(Boost 1.54.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(oppg2 echo_server.cpp)
target_link_libraries(oppg2 ${Boost_LIBRARIES})