cmake_minimum_required(VERSION 3.5)

project(axiocache LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(axiocache src/main.cpp
    src/cache/cachemanager.h src/cache/cachemanager.cpp
    src/cache/entry.h src/cache/entry.cpp
    src/callbacktimer.h src/callbacktimer.cpp)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

install(TARGETS axiocache LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
