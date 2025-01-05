#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		if (height.empty()) return 0;
		
		int N = height.size();
		vector<int> leftMax(N);
		vector<int> rightMax(N);

		leftMax[0] = height[0];
		for (int i = 1; i < N; i++) {
			leftMax[i] = max(leftMax[i-1], height[i]); 
		}

		rightMax[N-1] = height[N-1];
		for (int j = N - 2; j >= 0; j--) {
			rightMax[j] = max(rightMax[j+1], height[j]);
		}

		int res = 0;
		for (int i = 0; i < N; i++) {
			res += min(leftMax[i], rightMax[i]) - height[i];
		}

		return res;
	}

	int trapOptimal(vector<int>& height) {
		if (height.empty()) return 0;

		int N = height.size();
		int l = 0, r = N - 1;
		int leftMax = height[l], rightMax = height[r];
		int res = 0;

		while (l < r) {
			if (leftMax < rightMax) {
				res += leftMax - height[l];
				l += 1;
				leftMax = max(leftMax, height[l]);
			} else {
				res += rightMax - height[r];
				r -= 1;
				rightMax = max(rightMax, height[r]);
			}
		}

		return
	}
};

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
		}
	}

	return 0;
}