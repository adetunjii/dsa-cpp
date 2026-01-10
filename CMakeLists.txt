cmake_minimum_required(VERSION 3.25)

project(dsa_cpp
        VERSION 0.0.1
        DESCRIPTION "Data structures and Algorithms in c++"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

# Option to turn tests on/off
option(BUILD_TESTING "Build tests" ON)

include(CTest)
add_subdirectory(external)
add_subdirectory(coding_challenges/leetcode)
add_subdirectory(coding_challenges/tests/leetcode)