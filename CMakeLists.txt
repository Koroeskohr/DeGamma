cmake_minimum_required(VERSION 2.8)
project(DeGamma)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    find_package(SDL2 REQUIRED)
ELSE()
    find_package(SDL REQUIRED)
ENDIF()

find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

#set(OPENGL_LIBRARIES /usr/lib/x86_64-linux-gnu/libGL.so.1)
#IF(NOT ${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
#    set(OPENGL_LIBRARIES /usr/lib/x86_64-linux-gnu/libGL.so.1)
#ENDIF()

MESSAGE(STATUS "${CMAKE_MODULE_PATH}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wno-reorder -g")


IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    include_directories(${SDL2_INCLUDE_DIR})
ELSE()
    include_directories(${SDL_INCLUDE_DIR})
ENDIF()
include_directories(${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} glimac/include third-party/glm third-party/assimp/include/ third-party/rapidjson glimac/include/)


IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(ALL_LIBRARIES glimac assimp ${SDL2_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} ${ASSIMP_LIBRARY})
ELSE()
    set(ALL_LIBRARIES glimac assimp ${SDL_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} ${ASSIMP_LIBRARY})
ENDIF()

add_subdirectory(glimac)
add_subdirectory(third-party/assimp)

add_executable(projet main.cpp)
target_link_libraries(projet ${ALL_LIBRARIES})

file(COPY shaders DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
