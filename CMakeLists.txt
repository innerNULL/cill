# file: CMakeLists.txt
# date: 2020-07-23


cmake_minimum_required(VERSION 3.12.4)
project(cill C CXX)
enable_testing()


set(CMAKE_MACOSX_RPATH 1)

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

if(UNIX AND NOT APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
elseif(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif()


include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src/)
include_directories(${PROJECT_SOURCE_DIR}/include/)
include_directories(${PROJECT_SOURCE_DIR}/include/cill/3rdparty/)


set(RANDOM_KIT_DEMO src/demo/random_kit_demo.cpp)
add_executable(random_kit_demo ${RANDOM_KIT_DEMO})
set(ITERATOR_KIT_DEMO src/demo/iterator_kit_demo.cpp)
add_executable(iterator_kit_demo ${ITERATOR_KIT_DEMO})
set(STR_KIT_DEMO src/demo/str_kit_demo.cpp)
add_executable(str_kit_demo ${STR_KIT_DEMO})
set(SYS_KIT_DEMO src/demo/sys_kit_demo.cpp)
add_executable(sys_kit_demo ${SYS_KIT_DEMO})
