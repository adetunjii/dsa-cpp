#include <iostream>
#include <vector>
#include <ranges>

namespace dp{

int findNumberOfLIS(std::vector<int>& nums) {
    int N = nums.size();
    if (N == 1) return N;

    std::vector<int> length(N, 1);
    std::vector<int> count(N, 1);

    int maxLength = 1, res = 0;

    for (int i : std::views::iota(1, N)) {
        for (int j : std::views::iota(0, i)) {
            if (nums[i] > nums[j]) {
                if (length[i] == length[j] + 1) {
                    count[i] += count[j];
                }

                if (length[i] < length[j] + 1) {
                    length[i] = length[j] + 1;
                    count[i] = count[j]; // expanding the subsequence;
                }
            }
        }

        maxLength = std::max(maxLength, length[i]);
    }

    for (int i : std::views::iota(0, N)){
        if (length[i] == maxLength) res += count[i];
    }

    return res;
}
}