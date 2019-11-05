cmake_minimum_required(VERSION 3.2)

IF(DEFINED ENV{TRAVIS_BUILD_NUMBER})
    project(ip_filter VERSION $ENV{TRAVIS_BUILD_NUMBER})
ELSE()
    project(ip_filter VERSION 1)
ENDIF()

find_package(GTest REQUIRED)
find_package(Threads)
set(general_libs ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

add_library(byte_parser OBJECT byte_parser.cpp)

add_executable(
    byte_parser_test
    $<TARGET_OBJECTS:byte_parser>
    byte_parser_test.cpp
)
target_link_libraries(byte_parser_test ${general_libs})