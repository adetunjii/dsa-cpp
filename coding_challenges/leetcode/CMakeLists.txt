file (GLOB DP_FILES "dynamic_programming/*.cc")

# Create ONE library containing everything
add_library(leetcode ${DP_FILES})

# Ensure headers can be found
target_include_directories(leetcode PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})