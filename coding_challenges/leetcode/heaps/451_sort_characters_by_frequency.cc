#include <algorithm>
#include <map>
#include <queue>
#include <ranges>
#include <string>
using namespace std;

string frequencySort(string s) {
    int N = s.size();

    vector<int> vec(256, 0);

    for (int i : std::views::iota(0, 256)) {
        vec[s[i]]++;
    }

    std::priority_queue<pair<int, int>> pq;

    for (int i : std::views::iota(0, 256)) {
        pq.emplace(vec[i], i);
    }

    int k = 0;
    while (!pq.empty()) {
        auto [cnt, ch] = pq.top();

        while (cnt-- > 0) {
            s[k++] = ch;
        }
    }

    return s;
}