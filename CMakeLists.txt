cmake_minimum_required(VERSION 3.5)

project(axiocache LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(axiocache src/main.cpp)

install(TARGETS axiocache LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
