#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
	if (height.empty()) return 0;

	int m = 0;

	for (int i = 0; i < height.size(); i++) {
		for (j = i+1; j < height.size(); j++) {
			int height = min(height[i], height[j]);
			int width = j;
			m = max(height * width, m);
		}
	}

	return m;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		vector<int> heights;
		int num;
		while (cin.peek() != '\n' && cin.peek() != EOF) {
			cin >> num;
			heights.push_back(num);
		}
		cin.ignore();

		if (!heights.empty()) {
			cout << maxArea(heights) << "\n";
		}
	}

	return 0;
}