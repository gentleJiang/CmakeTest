# Sets the minimum version of CMake required to build the native
# library. You should either keep the default value or only pass a
# value of 3.4.0 or lower.

cmake_minimum_required(VERSION 3.4.1)

set(PROJECT_NAME CmakeTest_multiple_3)

project (${PROJECT_NAME})

aux_source_directory(. DIR_SRCS)

add_library( ${PROJECT_NAME} SHARED ${DIR_SRCS})


