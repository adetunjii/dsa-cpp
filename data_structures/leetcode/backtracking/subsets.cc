#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	auto res = subsets(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size; j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
}