#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>res;

void solve(vector<int>& nums, vector<int> out, int idx) {
    if (idx >= nums.size()) {
    	res.push_back(out);
    	return;
    }

    solve(nums, out, idx+1);`

    out.push_back(nums[idx]);
    solve(nums, out, idx+1);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> out;
    solve(nums, out, 0);
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