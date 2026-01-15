cmake_minimum_required(VERSION 3.14)
project(leetcode_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Add all test files
file(GLOB TEST_SOURCES "tests/*.cpp")

if(TEST_SOURCES)
    add_executable(leetcode_tests ${TEST_SOURCES})
    target_link_libraries(leetcode_tests GTest::gtest_main)
    include(GoogleTest)
    gtest_discover_tests(leetcode_tests)
endif()
