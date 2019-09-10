cmake_minimum_required(VERSION 3.2)

IF(DEFINED ENV{TRAVIS_BUILD_NUMBER})
    project(helloworld VERSION $ENV{TRAVIS_BUILD_NUMBER})
ELSE()
    project(helloworld VERSION 1)
ENDIF()

find_package(GTest REQUIRED)
configure_file(version.h.in version.h)

add_executable(helloworld main.cpp)
add_executable(test_ex test_version.cpp)

target_include_directories(
    helloworld
    PRIVATE 
    ${CMAKE_BINARY_DIR}
)

target_include_directories(
    test_ex
    PRIVATE
    ${CMAKE_BINARY_DIR}
    ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(test_ex ${GTEST_LIBRARIES} pthread)

install(TARGETS helloworld RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_CONTACT dywedodd@gmail.com)

include(CPack)

enable_testing()
add_test(NAME test_version COMMAND test_ex)