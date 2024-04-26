#include <iostream>
#include <vector>

using namespace std;

int fib(int n) {
    vector<int> bucket(n+1, -1);

    if(n <= 0) return 0;

    if (n <= 2) {
        bucket[n] = 1;
        return 1;
    }

    if (bucket[n-1] == -1) bucket[n-1] = fib(n-1);
    if (bucket[n-2] == -1) bucket[n-2] = fib(n-2);

    int f = bucket[n-1] + bucket[n-2];
    bucket[n] = f;
    return f;
}

int main() {
    int N;
    cin >> N;
    cout << fib(N) << endl;
    return 0;
}
