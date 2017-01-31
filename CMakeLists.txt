project(saper)
cmake_minimum_required(VERSION 3.5)

file(GLOB_RECURSE SRC ${CMAKE_SOURCE_DIR}/src/*.cpp ${CMAKE_SOURCE_DIR}/src/*.h)

add_executable(saper ${SRC})
