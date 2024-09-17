#include <iostream>
#include <vector>
#include <set>

using namespace std;

set<vector<int>> res;

void solve(vector<int>& nums, vector<int>& out, int idx) {
	int n = nums.size();
	if (idx >= n) {
		res.insert(out);
		return;
	}

	out.push_back(nums[idx]);
	solve(nums, out, idx+1);

	out.pop_back();
	solve(nums, out, idx+1);
}

vector<vector<int>> subsets(vector<int>& nums) {
	res = {};

	sort(nums.begin(), nums.end());
	vector<int> out;
	solve(nums, out, 0);
	
	vector<vector<int>> rv(res.begin(), res.end());
	return rv;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		vector<int> nums;
		int num;
		while (cin.peek() != '\n' && cin.peek() != EOF) {
			cin >> num;
			nums.push_back(num);
		}
		cin.ignore();

		if (!nums.empty()) {
			auto sol = subsets(nums);

			for (int i = 0; i < sol.size(); i++) {
				for (int j = 0; j < sol[i].size(); j++) {
					cout << sol[i][j] << " ";
				}
				cout << "\n";
			}
		}

	}

	return 0;
}