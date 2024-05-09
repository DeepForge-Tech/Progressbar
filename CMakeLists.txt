cmake_minimum_required(VERSION 3.18)
project(Progressbar)
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
set(CMAKE_CXX_STANDARD 20)
include(GNUInstallDirs)
option(BUILD_SHARED_LIBS OFF)
set(SOURCE_FILES
    include/Progressbar/Progressbar.hpp
    src/Progressbar.cpp
)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
if(BUILD_SHARED_LIBS)
    add_library(Progressbar SHARED ${SOURCE_FILES})
else()
    add_library(Progressbar STATIC ${SOURCE_FILES})
endif()