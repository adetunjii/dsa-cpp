#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

using triad = array<int, 3>;
using P = pair<int, int>;

int solve(vector<triad>& cows) {
    int N = cows.size();

    // sort the cows by arrival time
    sort(cows.begin(), cows.end());

    auto cmp = [](const triad& A, const triad& B) {
        return A[2] > B[2];
    };

    priority_queue<triad, std::vector<triad>, decltype(cmp)> waitList(cmp);

    int idx = 0;
    int running_time = 0;
    int res = 0;

    while (idx < N || waitList.size() > 0) {
        while (idx < N && running_time >= cows[idx][0]) {
            waitList.push(cows[idx]);
            idx += 1;
        }

        if (waitList.empty() && idx < N) {
            running_time = cows[idx][0] + cows[idx][1];
            idx += 1;
        }

        if (waitList.size() > 0) {
            res = max(res, running_time - waitList.top()[0]);
            running_time += waitList.top()[1];
            waitList.pop();
        }
    }

    return res;
}

int solveConventionII() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("convention2.in");

    int N;
    fin >> N;

    vector<triad> cows;

    for (int i = 0; i < N; i++) {
        int A, B;
        fin >> A >> B;
        cows.push_back({A, B, i});
    }

    ofstream fout("convention2.out");
    fout << solve(cows) << '\n';
}