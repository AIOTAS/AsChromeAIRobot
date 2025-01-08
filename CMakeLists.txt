cmake_minimum_required(VERSION 3.19)

project(as_chrome_robot)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/utils/
)

file(
    GLOB 
    SRC 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_executable(${PROJECT_NAME} ${SRC})