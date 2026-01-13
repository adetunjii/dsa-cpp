if(BUILD_TESTING)
	file(GLOB_RECURSE TEST_FILES "*.cc")

	add_executable(unittests ${TEST_FILES})

	target_link_libraries(unittests
		PRIVATE
			leetcode
			GTest::gtest
			GTest::gtest_main
	)

	include(GoogleTest)
	gtest_discover_tests(unittests)
endif()