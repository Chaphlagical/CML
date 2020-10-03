cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(CML VERSION 0.0.1)
message(STATUS "[Project] ${PROJECT_NAME} ${PROJECT_VERSION}")

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
include(InitProject)
Initcpkg()
Init_Project()

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

AddSubDirRec(src)