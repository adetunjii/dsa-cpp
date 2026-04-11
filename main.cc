#include <algorithm>
#include <functional>
#include <iostream>
#include <print>
#include <ranges>
#include <vector>

using namespace std;

int main() {
    int f[3] = {3, 2, 1};
    int g[5] = {1, 2, 3, 4, 5};

    // find the convolution after the 3rd day
    int days = 3;
    for (int x = 0; x < days; x++) {
        int sum = 0;

        for (int i = 0; i < 5; i++) {
            if (i < x) {
            }
            sum += f[i] + g[-i + x];
        }
    }
}