cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(Interview LANGUAGES CXX VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 14)
set(LIB_NAME "Interview")

add_library(${LIB_NAME} INTERFACE)
target_include_directories(${LIB_NAME} INTERFACE include/) 

if (NOT DISABLE_TESTS)
    add_subdirectory(external/Catch2)
    add_executable(${LIB_NAME}-tests
        test/test_main.cpp
        test/test_task_01.cpp
        test/test_task_02.cpp
        test/test_task_03.cpp
    )
    target_link_libraries(${LIB_NAME}-tests
        Catch2::Catch2
        Interview
    )
endif()