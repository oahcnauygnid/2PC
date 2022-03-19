# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT license.

cmake_minimum_required(VERSION 3.13)

project(2PC VERSION 3.7.2 LANGUAGES CXX)

# If not called from root CMakeLists.txt
if(NOT DEFINED SEAL_BUILD_EXAMPLES)
    set(SEAL_BUILD_EXAMPLES ON)

    # Import Microsoft SEAL
    find_package(SEAL 3.7.2 EXACT REQUIRED)


    message(">>> PROJECT_SOURCE_DIR is ${PROJECT_SOURCE_DIR}")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
endif()

if(SEAL_BUILD_EXAMPLES)
    add_executable(module)

    target_sources(module
        PRIVATE
            module.cpp
    )

    if(TARGET SEAL::seal)
        target_link_libraries(module PRIVATE SEAL::seal)
    elseif(TARGET SEAL::seal_shared)
        target_link_libraries(module PRIVATE SEAL::seal_shared)
    else()
        message(FATAL_ERROR "Cannot find target SEAL::seal or SEAL::seal_shared")
    endif()
endif()
