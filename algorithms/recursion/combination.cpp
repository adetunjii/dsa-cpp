#include <iostream>

using namespace std;

// based on pascal's triangle.
int combine(int n, int r) {
    if (r == 0 || n == r) {
        return 1;
    } else {
        return combine(n-1, r-1) + combine(n-1, r);
    }
}

int main() {
    cout << combine(4, 2) << endl;
    return 0;
}