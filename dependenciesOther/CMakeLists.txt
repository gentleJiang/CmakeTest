# Sets the minimum version of CMake required to build the native
# library. You should either keep the default value or only pass a
# value of 3.4.0 or lower.

cmake_minimum_required(VERSION 3.4.1)

set(PROJECT_NAME dependencies)

project(${PROJECT_NAME})

# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file (
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
    )

option (SWITCH "Use provided math implementation" ON)

if(SWITCH)

endif(SWITCH)

include_directories(${SRC_DIR}/include)

include_directories(${PROJECT_BINARY_DIR})

set(SRC_DIR src)

#指定当前目录下的所有.cpp文件（包括子目录）
file(GLOB_RECURSE cpp_src "${SRC_DIR}/*.cpp")

add_library(${PROJECT_NAME} SHARED ${cpp_src} )

find_library(log-lib log)

set(LINK_LIB_DIR ${CMAKE_SOURCE_DIR}/src/main/libs/${ANDROID_ABI})

add_library(serial_port SHARED IMPORTED)
set_target_properties(serial_port PROPERTIES IMPORTED_LOCATION ${LINK_LIB_DIR}/libserial_port.so)

target_link_libraries(${PROJECT_NAME}
                      serial_port

                      ${log-lib} )


