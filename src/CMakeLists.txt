cmake_minimum_required(VERSION 3.5)

project(Str-lib LANGUAGES CXX)

set(NODE_DIR "${PROJECT_SOURCE_DIR}/node")

file(GLOB STR_SOURCE_FILES
        "${NODE_DIR}/*.cpp"
        "${PROJECT_SOURCE_DIR}/*.cpp"
        )

file(GLOB STR_HEADERS_FILES
        "${NODE_DIR}/*.h"
        "${PROJECT_SOURCE_DIR}/*.h"
        )


add_library(libstc ${STR_SOURCE_FILES} ${STR_HEADERS_FILES})

target_include_directories(libstc
    PUBLIC
        ${PROJECT_SOURCE_DIR}
        ${NODE_DIR})
