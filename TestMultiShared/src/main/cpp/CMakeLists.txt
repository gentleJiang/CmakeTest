# Sets the minimum version of CMake required to build the native
# library. You should either keep the default value or only pass a
# value of 3.4.0 or lower.

cmake_minimum_required(VERSION 3.4.1)

add_subdirectory(lic)#指定子文件夹

add_subdirectory(serialport)

add_subdirectory(pin)


