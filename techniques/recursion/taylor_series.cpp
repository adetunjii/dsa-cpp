#include <iostream>

using namespace std;

double series(int x, int n) {
    static double p = 1, f = 1;
    if (n == 0) {
        return 1;
    } else {
        double r = series(x, n - 1);
        p = p * x;
        f = f * n;

        return r + p/f;
    }
}

int main() {

    cout << series(2, 10) << endl; 

    return 0;
}