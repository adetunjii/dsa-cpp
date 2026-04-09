#include <algorithm>
#include <iostream>
#include <queue>
#include <ranges>
#include <vector>

using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<pair<int, int>> vec;

    for (int i : views::iota(0, N)) {
        int A, B;
        cin >> A >> B;
        vec.emplace_back(A, B);
    }

    // sort ranges
    sort(vec.begin(), vec.end());

    int idx = 0;
    int box = 1;
    int placed = 0;

    priority_queue<int, std::vector<int>, std::greater<>> pq;

    while (placed < N) {
        while (idx < N && box == vec[idx].first) {
            pq.push(vec[idx].second);
            idx += 1;
        }

        if (pq.empty()) {
            if (idx < N) {
                box = vec[idx].first;
                continue;
            } else {
                cout << "No" << '\n';
                return;
            }
        }

        int r = pq.top();
        if (box > r) {
            cout << "No" << '\n';
            return;
        }
        pq.pop();
        placed += 1;
        box += 1;
    }

    cout << "Yes" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testcases;
    cin >> testcases;

    while (testcases-- > 0) {
        solve();
    }
}