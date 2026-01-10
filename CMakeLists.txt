cmake_minimum_required(VERSION 3.17..3.25)
project(dsa_cpp 
		VERSION 0.0.1
		DESCRIPTION "Data structures & Algorithms in C++"
		LANGUAGES CXX
	)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
add_subdirectory(external)
add_subdirectory(coding_challenges/leetcode)
add_subdirectory(coding_challenges/tests/leetcode)