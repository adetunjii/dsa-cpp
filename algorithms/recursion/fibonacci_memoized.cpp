#include <iostream>
#include <vector>

using namespace std;


int fib(int n) {   

    vector<int> bucket(n+1, -1);

    if (n <= 1) {
        bucket[n] = n;
        return n;
    } else {
        if (bucket[n-2] == -1) {
            bucket[n-2] = fib(n-2);
        }

        if (bucket[n-1] == -1) {
            bucket[n-1] = fib(n-1);
        }
        bucket[n] = bucket[n-2] + bucket[n-1];
        return bucket[n-2] + bucket[n-1];
    }
}

int main() {

    cout << fib(3) << endl;

    return 0;
}
