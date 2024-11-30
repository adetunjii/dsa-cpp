#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		vector<int> heights;
		int num;
		while (cin.peek() != '\n' && cin.peek() != EOF) {
			cin >> num;
			heights.push_back(num);
		}
		cin.ignore();

		if (!heights.empty()) {
			// cout << maxAreaOptimal(heights) << "\n";
		}
	}

	return 0;
}