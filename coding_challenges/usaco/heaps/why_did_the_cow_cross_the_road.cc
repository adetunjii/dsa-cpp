#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solve(vector<int>& chickens, vector<pair<int, int>> cows) {
    int M = cows.size();

    int idx = 0, count = 0;

    priority_queue<int, vector<int>, greater<>> waitList;

    for (int& c : chickens) {
        while (idx < M && c >= cows[idx].first) {
            waitList.push(cows[idx].second);
            idx += 1;
        }

        // remove unprocessable cows from the waitList
        while (!waitList.empty() && c > waitList.top()) {
            waitList.pop();
        }

        if (!waitList.empty() && c <= waitList.top()) {
            waitList.pop();
            count += 1;
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("helpcross.in");

    int numChickens, numCows;
    fin >> numChickens >> numCows;

    vector<int> chickens(numChickens);
    vector<pair<int, int>> cows(numCows);

    for (auto& chicken : chickens) {
        fin >> chicken;
    }

    for (auto& cow : cows) {
        fin >> cow.first >> cow.second;
    }

    sort(cows.begin(), cows.end());
    sort(chickens.begin(), chickens.end());

    ofstream fout("helpcross.out");
    fout << solve(chickens, cows) << '\n';
}