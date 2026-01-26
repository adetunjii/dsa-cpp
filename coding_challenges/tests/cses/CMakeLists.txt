if (BUILD_TESTING)
	file(GLOB_RECURSE CSES_TEST_FILES "*.cc")

	add_executable(cses_tests ${CSES_TEST_FILES})

	target_link_libraries(cses_tests
		PRIVATE
			cses
			GTest::gtest
			GTest::gtest_main
	)

	include(GoogleTest)
	gtest_discover_tests(cses_tests)
endif()