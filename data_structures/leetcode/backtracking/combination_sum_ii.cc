#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> res;
int target;

void solve(vector<int>& nums, vector<int>& out, const int& sum, int idx) {
	int n = nums.size();

	if (sum == target) {
		if (!out.empty())
			res.push_back(out);
		return;
	}
	
	if (idx >= n || sum > target) return;

	// problem is that it a number can be repeated until the problem is solved
	for (int i = idx; i < n; i++) {
		if (i > idx && nums[i] == nums[i-1]) continue;

		out.push_back(nums[i]);
		solve(nums, out, sum + nums[i], i);

		out.pop_back();
	}
}

void combinationSum(vector<int>& candidates, int t) {
	target = t;
	vector<int> out;
	sort(candidates.begin(), candidates.end());
	solve(candidates, out, 0, 0);
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(6);
	nums.push_back(7);

	int target = 7;

	combinationSum(nums, target);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
}