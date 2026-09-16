#include <ranges>

namespace Dp {
int tribonacci(int N) {
    if (N == 0) return 0;
    if (N <= 2) return 1;

    int A = 0, B = 1, C = 1, res = 0;
    for (int i : std::views::iota(2, N)) {
        res = A + B + C;
        A = B;
        B = C;
        C = res;
    }

    return res;
} 
}