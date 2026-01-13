file(GLOB DP_FILES "dynamic_programming/*.cc")

add_library(leetcode ${DP_FILES})

target_include_directories(leetcode PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")