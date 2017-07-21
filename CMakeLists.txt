project(saper)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

file(GLOB_RECURSE CLI_SRC  ${CMAKE_SOURCE_DIR}/src/cli/*.cpp ${CMAKE_SOURCE_DIR}/src/cli/*.h)
file(GLOB_RECURSE LIB_SRC  ${CMAKE_SOURCE_DIR}/src/engine/*.cpp ${CMAKE_SOURCE_DIR}/src/engine/*.h)
file(GLOB_RECURSE TEST_SRC ${CMAKE_SOURCE_DIR}/test/*.cpp ${CMAKE_SOURCE_DIR}/test/*.h)
include_directories(${CMAKE_SOURCE_DIR}/src/)
add_library(saperengine STATIC ${LIB_SRC})

add_executable(saper ${CLI_SRC})
target_link_libraries(saper saperengine)

add_executable(ut ${TEST_SRC} ${LIB_SRC})
target_include_directories(ut PRIVATE
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/external>
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src>
)
