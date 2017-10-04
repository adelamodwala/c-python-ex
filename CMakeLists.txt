cmake_minimum_required(VERSION 3.7)
project(c_python_ex)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        spammodule.c)

add_executable(c_python_ex ${SOURCE_FILES})