cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(CMakeClientTest
    LANGUAGES CXX
)

set(STLSoft_REQUIRED_VERSION_ 1.10.2)
set(WilliamsCRC_REQUIRED_VERSION_ 2.0)
set(recls_REQUIRED_VERSION_ 1.10)
set(xTests_REQUIRED_VERSION_ 0.20)

find_package(STLSoft ${} REQUIRED)
message("-- CMake package STLSoft found (version ${STLSoft_VERSION}; ${STLSoft_REQUIRED_VERSION_} requested)")

find_package(WilliamsCRC ${WilliamsCRC_REQUIRED_VERSION_} REQUIRED)
message("-- CMake package WilliamsCRC found (version ${WilliamsCRC_VERSION}; ${WilliamsCRC_REQUIRED_VERSION_} requested)")

find_package(recls ${recls_REQUIRED_VERSION_} REQUIRED)
message("-- CMake package recls found (version ${recls_VERSION}; ${recls_REQUIRED_VERSION_} requested)")

find_package(xTests ${xTests_REQUIRED_VERSION_} REQUIRED)
message("-- CMake package xTests found (version ${xTests_VERSION}; ${xTests_REQUIRED_VERSION_} requested)")


add_subdirectory(test)
add_subdirectory(tools)


