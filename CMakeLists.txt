cmake_minimum_required(VERSION 2.8)
project(DeGamma)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

add_subdirectory(glimac)


add_library(glimac ${GLIMAC_FILES})
add_library(third-party ${THIRD_PARTY_FILES})

add_executable(projet main.cpp glimac third-party)