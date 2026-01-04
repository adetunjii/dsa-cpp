#include <iostream>
#include <vector>
#include <print>
#include <algorithm>
#include <functional>

int main(int argc, char* argv[]) {
	std::vector<int> V = {1, 2, 3, 8, 0, 4, 5, 9};

	auto lessThanFunc = [](int a, int b) { return a < b; };

	auto printFunc = [](auto& item) { std::print("{}, ", item); };

	// Sorting with Lambda
	std::sort(std::begin(V), std::end(V), lessThanFunc);
	std::print("Sorted with a Lambda function: ");
	std::ranges::for_each(V, printFunc);
	std::println();

	// Sorting with functors
	struct {
		inline bool operator() (int a, int b) { return a < b ; }
	} customLessThan;

	std::print("Sorted with a Functor: ");
	std::sort(std::begin(V), std::end(V), customLessThan);
	std::ranges::for_each(V, printFunc);
	std::println();

	// Sorting with stdlib compare functions
	std::sort(std::begin(V), std::end(V), std::less<int>());
	std::print("Sorted with stdlib compare function: ");
	std::ranges::for_each(V, printFunc);
	std::println();

	// Don't like iterators, use range-based sorting. 
	std::ranges::sort(V, lessThanFunc);
	std::print("Sorted using range-based sorting + lambda: ");
	std::ranges::for_each(V, printFunc);
	std::println();
}