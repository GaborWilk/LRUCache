cmake_minimum_required(VERSION 3.8)

project(LRUCache LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra")

set(SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/src/test.cpp)

set(HEADER_FILES
    ${PROJECT_SOURCE_DIR}/include/catch.hpp
    ${PROJECT_SOURCE_DIR}/include/LRUCache.h)

include_directories("${CMAKE_SOURCE_DIR}/include")

add_executable(LRUCache ${SOURCE_FILES} ${HEADER_FILES})
