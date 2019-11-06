cmake_minimum_required(VERSION 3.2)

IF(DEFINED ENV{TRAVIS_BUILD_NUMBER})
    project(ip_filter VERSION $ENV{TRAVIS_BUILD_NUMBER})
ELSE()
    project(ip_filter VERSION 1)
ENDIF()

find_package(GTest REQUIRED)
find_package(Threads)
set(general_libs ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

add_library(ipv4 OBJECT ipv4.cpp)
add_library(byte_parser OBJECT byte_parser.cpp)
add_library(
    ip_parser STATIC
    $<TARGET_OBJECTS:byte_parser>
    $<TARGET_OBJECTS:ipv4>
    ip_parser.cpp
)

add_executable(
    byte_parser_test
    $<TARGET_OBJECTS:byte_parser>
    byte_parser_test.cpp
)
target_link_libraries(byte_parser_test ${general_libs})

add_executable(
    ip_parser_test
    ip_parser_test.cpp
)
target_link_libraries(ip_parser_test ip_parser ${general_libs})

enable_testing()
add_test(NAME byte_parser_test COMMAND byte_parser_test)
add_test(NAME ip_parser_test COMMAND ip_parser_test)