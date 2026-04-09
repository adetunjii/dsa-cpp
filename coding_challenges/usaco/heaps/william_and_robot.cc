#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;

ll solve(vector<int> nums) {
    int N = nums.size();
    priority_queue<int, vector<int>, greater<>> pq;

    for (int i = 0; i < N; ++i) {
        pq.push(nums[i]);
        if (i & 1) {
            pq.pop();
        }
    }

    ll sum = 0;
    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> nums(N);

    for (int& i : nums) {
        cin >> i;
    }

    cout << solve(nums) << '\n';
}