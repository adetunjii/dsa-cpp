#include <iostream>
#include <vector>

using namespace std;

int solve(int n, vector<int>& nums) {
	int target = 0;

	for (int i = 0; i < n - 1; i++) {
		target ^= nums[i];
		target ^= (i + 1); 
	}
	
	return target ^ n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (cin.peek() != EOF) {
		int N;
		cin >> N;

		cin.ignore();
		vector<int> A;
		while (cin.peek() != '\n' && cin.peek() != EOF) {
			int num;
			cin >> num;
			A.push_back(num);
		}
		cout << solve(N, A) << "\n";
		cin.ignore();
	}

	return 0;
}