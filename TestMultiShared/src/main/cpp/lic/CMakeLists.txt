# Sets the minimum version of CMake required to build the native
# library. You should either keep the default value or only pass a
# value of 3.4.0 or lower.

cmake_minimum_required(VERSION 3.4.1)

set(PROJECT_NAME CmakeTest_multiple)

project (${PROJECT_NAME})

set(SRC_DIR ../lic)

#指定当前目录下的所有.cpp文件（包括子目录）
file(GLOB_RECURSE cpp_src "${SRC_DIR}/*.cpp")

add_library( ${PROJECT_NAME} SHARED ${cpp_src})


