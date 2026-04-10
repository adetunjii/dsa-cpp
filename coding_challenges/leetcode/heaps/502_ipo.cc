#include <bits/stdc++.h>
#include <ranges>

int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
    int N = profits.size();

    std::vector<std::pair<int, int>> vec;

    for (int i : std::views::iota(0, N)) {
        vec.emplace_back(capital[i], i);
    }

    sort(vec.begin(), vec.end());

    int availableCapital = w;

    std::priority_queue<int> waitList;
    int idx = 0;
    int c = 0;

    while (c < N) {
        while (waitList.size() < k && c < N && availableCapital >= vec[c].first) {
            waitList.push(profits[vec[c].second]);
            c += 1;
        }

        if (waitList.empty() && availableCapital < vec[c].first) {
            availableCapital = vec[c].first;
            continue;
        }

        availableCapital += waitList.top();
        waitList.pop();
    }

    return availableCapital;
}
