project(saper)
cmake_minimum_required(VERSION 3.5)

file(GLOB_RECURSE CLI_SRC ${CMAKE_SOURCE_DIR}/src/cli/*.cpp ${CMAKE_SOURCE_DIR}/src/cli/*.h)
file(GLOB_RECURSE LIB_SRC ${CMAKE_SOURCE_DIR}/src/engine/*.cpp ${CMAKE_SOURCE_DIR}/src/engine/*.h)

add_library(saperengine STATIC ${LIB_SRC})

add_executable(saper ${CLI_SRC})
target_link_libraries(saper saperengine)
#add_executable(ut )
