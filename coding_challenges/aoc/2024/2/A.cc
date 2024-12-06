#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

bool isIncreasing(vector<int>& list) {
    int prev = list[0];
    for (int i = 1; i < list.size(); i++) {
        if (list[i] > prev && (abs(list[i] - prev) <= 3)) {
            prev = list[i];
        } else { return false; }
    }
    return true;
}

bool isDecreasing(vector<int>& list) {
    int N = list.size() - 1;
    int prev = list[N];
    for (int i = N - 1; i >= 0; i--) {
        if (list[i] > prev && (abs(list[i] - prev) <= 3)) {
            prev = list[i];
        } else { return false; }
    } 
    return true;
}

int isValid(vector<int>& list) {
    return isIncreasing(list) || isDecreasing(list) ? 1 : 0;
}

int main() {
    int count = 0;
    string line;
    while(getline(cin, line)) {
        vector<int> list;
        stringstream iss(line);
        int N;
        while (iss >> N) {
            list.push_back(N);
        }
        count += isValid(list);
    }

    cout << count << endl;
    return 0;
}
