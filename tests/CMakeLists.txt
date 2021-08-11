cmake_minimum_required(VERSION 3.5)

project(tests LANGUAGES CXX)

set(QUEUE_TEST_CASE_DIR "${PROJECT_SOURCE_DIR}/queue_test")
set(STACK_TEST_CASE_DIR "${PROJECT_SOURCE_DIR}/stack_test")

add_subdirectory(${QUEUE_TEST_CASE_DIR})
add_subdirectory(${STACK_TEST_CASE_DIR})
