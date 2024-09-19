#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums) {
	int n = nums.size();

	int target = 0;
	for (int i = 0; i < n; i++) {
		target ^= nums[i];
		target ^= (i + 1); 
	}
	
	return target;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

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

		if (!nums.empty())
			cout << missingNumber(nums) << "\n";
	}

	return 0;
}