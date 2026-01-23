#include <vector>
#include <ranges>

namespace bitwiseOp {
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        int N = nums.size();
        std::vector<std::vector<int>> res;

        for (int i = 0; i < (1 << N); i++) {
            std::vector<int> subset;
            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) {
                    subset.push_back(nums[i]);
                }
            }
            res.push_back(subset);
        }

        return res;
    }
}