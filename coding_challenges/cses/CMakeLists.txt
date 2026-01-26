file(GLOB CSES_FILES "*.cc")

add_library(cses ${CSES_FILES})

target_include_directories(cses PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")