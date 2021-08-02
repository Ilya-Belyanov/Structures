cmake_minimum_required(VERSION 3.5)

project(str)

set(NODE_DIR "${PROJECT_SOURCE_DIR}/node")

file(GLOB STR_HEADERS_FILES
        "${NODE_DIR}/*.hpp"
        "${PROJECT_SOURCE_DIR}/*.hpp"
        )

add_library(${PROJECT_NAME} SHARED ${STR_HEADERS_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${NODE_DIR}
        ${PROJECT_SOURCE_DIR})
