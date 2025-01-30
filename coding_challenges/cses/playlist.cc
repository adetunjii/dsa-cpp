#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N; 
    cin >> N;
    vector<int> A(200000);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    set<int> s;
    int l = 0;
    int maxWindow = 0;
    for (int r = 0; r < N; r++) {
        while(s.count(A[r]) > 0) {
            s.erase(A[l]);
            l += 1;
        } 
        s.insert(A[r]);
        maxWindow = max(maxWindow, r-l+1);
    }
    cout << maxWindow;
}