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
    for (int i : std::views::iota(0, N)) {
        int A, B;
        cin >> A >> B;
        vec.emplace_back(A, B);
    }

    sort(vec.begin(), vec.end());

    int idx = 0;
    int box = 1;
    int placed = 0;

    priority_queue<int, vector<int>, greater<>> waitList;

    while (placed < N) {
        while (idx < N && box == vec[idx].first) {
            waitList.push(vec[idx].second);
            idx += 1;
        }

        // don't wait idle
        if (waitList.empty() && idx < N && box < vec[idx].first) {
            box = vec[idx].first;
            continue;
        }

        if (box > waitList.top()) {
            cout << "No" << '\n';
            return;
        }

        waitList.pop();

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