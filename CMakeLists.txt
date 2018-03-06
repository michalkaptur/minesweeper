project(saper)
cmake_minimum_required(VERSION 3.1)

set (CMAKE_CXX_STANDARD 14)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lc++ -lc++abi -lm -lc -lgcc_s -lgcc")
endif()

file(GLOB_RECURSE CLI_SRC  ${CMAKE_SOURCE_DIR}/src/cli/*.cpp ${CMAKE_SOURCE_DIR}/src/cli/*.h)
file(GLOB_RECURSE LIB_SRC  ${CMAKE_SOURCE_DIR}/src/engine/*.cpp ${CMAKE_SOURCE_DIR}/src/engine/*.h)
file(GLOB_RECURSE TEST_SRC ${CMAKE_SOURCE_DIR}/test/*.cpp ${CMAKE_SOURCE_DIR}/test/*.h)
include_directories(${CMAKE_SOURCE_DIR}/src/)
add_library(saperengine STATIC ${LIB_SRC})

add_executable(saper ${CLI_SRC})
target_link_libraries(saper saperengine)

add_executable(ut ${TEST_SRC})
target_link_libraries(ut saperengine gtest gtest_main pthread)
