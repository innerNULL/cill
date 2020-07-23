cmake_minimum_required(VERSION 3.14.5)
project(cill C CXX)
enable_testing()
set(CMAKE_MACOSX_RPATH 1)


if(UNIX AND NOT APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
elseif(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif()


include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src/)
include_directories(${PROJECT_SOURCE_DIR}/include/)
include_directories(${PROJECT_SOURCE_DIR}/include/cill/3rdparty/)


set(NUM_KIT_DEMO src/demo/num_kit_demo.cpp)
add_executable(num_kit_demo ${NUM_KIT_DEMO})

