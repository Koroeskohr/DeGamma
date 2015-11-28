cmake_minimum_required(VERSION 2.8)
project(DeGamma)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

find_package(SDL REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

set(OPENGL_LIBRARIES /usr/lib/x86_64-linux-gnu/libGL.so.1)

MESSAGE(STATUS "${CMAKE_MODULE_PATH}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${SDL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} glimac/include third-party/glm third-party/assimp/include/)

set(ALL_LIBRARIES glimac assimp ${SDL_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} ${ASSIMP_LIBRARY})
add_subdirectory(glimac)
add_subdirectory(third-party/assimp)

add_executable(projet main.cpp)
target_link_libraries(projet ${ALL_LIBRARIES})