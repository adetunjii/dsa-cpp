#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxAreaOptimal(vector<int>& height) {
	if (height.empty()) return 0;

	int m = 0;
	int left = 0, right = height.size()-1; 

	while (left < right) {
		m = max(m, (right-left) * min(height[right], height[left]));

		if (height[left] > height[right]) {
			right -= 1;
		} else {
			left += 1;
		}
	}

	return m;
}

int maxArea(vector<int>& height) {
	if (height.empty()) return 0;

	int m = 0;

	for (int i = 0; i < height.size(); i++) {
		for (int j = i+1; j < height.size(); j++) {
			int h = min(height[i], height[j]) * (j - i);
			m = max(h, m);
		}
	}

	return m;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

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
			cout << maxAreaOptimal(heights) << "\n";
		}
	}

	return 0;
}