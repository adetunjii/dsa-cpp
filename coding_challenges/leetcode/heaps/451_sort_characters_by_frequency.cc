#include <algorithm>
#include <map>
#include <queue>
#include <ranges>
#include <string>
using namespace std;

string frequencySort(string s) {
    int N = s.size();

    map<char, int> m;

    for (auto& c : s) {
        if (m.count(c) == 0) {
            m.insert({c, 1});
        } else {
            m[c] += 1;
        }
    }

    auto cmp = [](pair<char, int> A, pair<char, int> B) {
        return A.second < B.second;
    };

    std::priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(m.begin(),
                                                                                    m.end());

    string res = "";
    while (!pq.empty()) {
        res += string(pq.top().second, pq.top().first);
        pq.pop();
    }

    return res;
}