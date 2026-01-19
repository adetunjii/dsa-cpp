#include <iostream>
#include <vector>

std::vector<std::vector<int>> res;

void dfs(std::vector<int>& nums, std::vector<int>& subset, int idx) {
	if (idx >= nums.size()) {
		res.push_back(subset);
		return;
	}

	dfs(nums, subset, idx+1);
	subset.push_back(nums[idx]);
	dfs(nums, subset, idx+1);
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<int> subset;
	dfs(nums, subset, 0);
	return res;
}


int main() {

	vector<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);

	auto r = subsets(test);

	for (int i = 0; i < r.size(); i++) {
		for (int j = 0; j < r[i].size(); j++) {
			cout << r[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}