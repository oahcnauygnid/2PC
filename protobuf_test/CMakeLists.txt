# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT license.

cmake_minimum_required(VERSION 3.0)
project(PT)
# Import Microsoft SEAL
find_package(Protobuf REQUIRED)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
message("${PROTOBUF_LIBRARIES}")

add_executable(protobuf_test protobuf_test.cpp protobuf_test.pb.cc)
target_link_libraries(protobuf_test ${PROTOBUF_LIBRARIES})

