cmake_minimum_required(VERSION 3.2)

IF(DEFINED ENV{TRAVIS_BUILD_NUMBER})
    project(helloworld VERSION $ENV{TRAVIS_BUILD_NUMBER})
ELSE()
    project(helloworld VERSION 1)
ENDIF()

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
find_package(GTest REQUIRED)
configure_file(version.h.in version.h)

add_executable(helloworld main.cpp)
add_executable(boost_test_executable boost_test_version.cpp)
add_executable(google_test_executable google_test_version.cpp)

target_include_directories(
    helloworld
    PRIVATE 
    ${CMAKE_BINARY_DIR}
)

target_include_directories(
    boost_test_executable
    PRIVATE 
    ${CMAKE_BINARY_DIR}
    ${Boost_INCLUDE_DIR}
)

target_include_directories(
    google_test_executable
    PRIVATE
    ${CMAKE_BINARY_DIR}
    ${GTEST_INCLUDE_DIRS}
)

target_compile_definitions(boost_test_executable PRIVATE "BOOST_TEST_DYN_LINK=1")

target_link_libraries(boost_test_executable ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(google_test_executable ${GTEST_LIBRARIES} pthread)

enable_testing()
add_test(NAME test_version1 COMMAND boost_test_executable)
add_test(NAME test_version2 COMMAND google_test_executable)