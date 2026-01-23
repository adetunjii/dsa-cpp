#include <iostream>
#include <vector>
#include <print>
#include <ranges>
#include <algorithm>
#include <functional>


void dfs(std::vector<int>& nums, int idx, std::vector<std::vector<int>>& res, std::vector<int>& subset) {
	int N = nums.size();
	if (idx >= N) {
		res.push_back(subset);
		return;
	}

	subset.push_back(nums[idx]);
	dfs(nums, idx+1, res, subset);

	subset.pop_back();
	dfs(nums, idx+1, res, subset);
}

int main(int argc, char* argv[]) {
	std::vector<int> nums = {1, 2, 3};
	std::vector<std::vector<int>> res;
	std::vector<int> subset;

	dfs(nums, 0, res, subset);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			std::cout << "{" << res[i][j] << "} ";
		}
		std::cout << '\n'; 
	}

	return 0;
}
