#include <iostream>

using namespace std;

void solve(int n, vector<int>& nums) {
	
	vector<int> bucket(n+1, -1);

	for (int i = 0; i < nums.size(); i++) {
		bucket[nums[i]] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (bucket[i] == -1) {
			cout << i << "\n";
		}
	} 
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
		while (cin.peek() != '\n') {
			int num;
			cin >> num;
			A.push_back(num);
		}
		solve(N, A);
	}
	cin.ignore();

	return 0;
}