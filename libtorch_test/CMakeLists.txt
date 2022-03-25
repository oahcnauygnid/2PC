# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT license.

cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(libtorch_test)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
find_package(Torch REQUIRED)
add_executable(libtorch_test libtorch_test.cpp)
target_link_libraries(libtorch_test "${TORCH_LIBRARIES}")
set_property(TARGET libtorch_test PROPERTY CXX_STANDARD 14)