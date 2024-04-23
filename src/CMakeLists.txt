cmake_minimum_required(VERSION 3.5)
set(target wjutils)
project(${target})

add_definitions("-D_PLATFORM_WIN_")
add_definitions("-DWJ_EXPORT")
set(targetStaticLib "${target}.lib")
set(targetDynamicLib "${target}.dll")
if(CMAKE_BUILD_TYPE STREQUAL "CMAKE_BUILD_TYPE")
	message(STATUS "CMAKE_BUILD_TYPE empty!")
	set(CMAKE_BUILD_TYPE "Debug")
endif()
message(STATUS "CMAKE_BUILD_TYPE:" ${CMAKE_BUILD_TYPE})
message(STATUS "CMAKE_SIZEOF_VOID_P:" ${CMAKE_SIZEOF_VOID_P})
if(${CMAKE_SIZEOF_VOID_P} STREQUAL "8")
  message(STATUS "architecture is x64!")
else()
  message(STATUS "architecture is x86!")
endif()
message("targetStaticLib:" ${targetStaticLib})
message(STATUS "PROJECT_SOURCE_DIR:" ${PROJECT_SOURCE_DIR})
message(STATUS "PROJECT_BINARY_DIR:" ${PROJECT_BINARY_DIR})
message(STATUS "CMAKE_SOURCE_DIR:" ${CMAKE_SOURCE_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
message(STATUS "LIBRARY_OUTPUT_PATH:" ${LIBRARY_OUTPUT_PATH})
include_directories(include)
include_directories(src)
include_directories(../include)

file(GLOB SRC_LIST
"*.cpp"
"src/*.cpp")

file(GLOB HEADER_LIST
"*.h"
"../include/*.h")

add_library(${target} SHARED ${SRC_LIST} ${HEADER_LIST})

string(REPLACE "/" "\\" CMAKE_SOURCE_DIR_WIN ${CMAKE_SOURCE_DIR})
string(REPLACE "/" "\\" LIBRARY_OUTPUT_PATH_WIN ${LIBRARY_OUTPUT_PATH})
message(STATUS ${LIBRARY_OUTPUT_PATH_WIN})
add_custom_command(TARGET ${target}
POST_BUILD
COMMAND xcopy ${CMAKE_SOURCE_DIR_WIN}\\include\\ ${CMAKE_SOURCE_DIR_WIN}\\..\\selfLearning\\libs\\wjutils\\include\\ /e /s /y
COMMAND copy ${LIBRARY_OUTPUT_PATH_WIN}\\${CMAKE_BUILD_TYPE}\\${targetStaticLib} ${CMAKE_SOURCE_DIR_WIN}\\..\\selfLearning\\libs\\Debug\\wjutils\\${targetStaticLib}
COMMAND copy ${LIBRARY_OUTPUT_PATH_WIN}\\${CMAKE_BUILD_TYPE}\\${targetDynamicLib} ${CMAKE_SOURCE_DIR_WIN}\\..\\selfLearning\\libs\\${CMAKE_BUILD_TYPE}\\wjutils\\${targetDynamicLib}
)