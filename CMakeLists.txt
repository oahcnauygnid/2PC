# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT license.

cmake_minimum_required(VERSION 3.0)
project(2PC)
# Import Microsoft SEAL
find_package(SEAL 3.7.2 EXACT REQUIRED)
find_package(Torch REQUIRED)
#message(">>> PROJECT_SOURCE_DIR is ${PROJECT_SOURCE_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(module module.cpp)
target_link_libraries(module PRIVATE SEAL::seal "${TORCH_LIBRARIES}")

