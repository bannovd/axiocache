cmake_minimum_required(VERSION 3.5)

project(simple-cache LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(simple-cache src/main.cpp
    src/cache/cachemanager.h src/cache/cachemanager.cpp
    src/cache/entry.h src/cache/entry.cpp
    src/callbacktimer.h src/callbacktimer.cpp
    src/config.h src/config.cpp
    src/cache/icacheclearstrategy.h
    src/cache/expiredttlstrategy.h src/cache/expiredttlstrategy.cpp
    src/cache/cachegarbagecollector.h src/cache/cachegarbagecollector.cpp
    src/logger.h src/logger.cpp)


find_package(Boost COMPONENTS REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

install(TARGETS simple-cache LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
