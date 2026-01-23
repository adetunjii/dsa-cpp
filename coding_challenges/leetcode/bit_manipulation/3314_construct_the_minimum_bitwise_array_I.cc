#include <vector>
#include <ranges>

namespace bitwiseOp{
	std::vector<int> minBitwiseArray(std::vector<int>& nums) {
		int N = nums.size();

		// 1001 being the maximum nums[i] there can be.
		int maxInt = 1001;
		std::vector<int> ans(N, maxInt);

		for (int i : std::views::iota(0, N)) {
			for (int j : std::views::iota(0, nums[i] + 1)) {
				if ((j | (j+1)) == nums[i]) {
					ans[i] = std::min(ans[i], j);
				}
			}

			// if after scanning, no number can be found, ans[i] = -1;
			if (ans[i] == maxInt) ans[i] = -1;
		}

		return ans;

	}	

	std::vector<int> minBitwiseArrayOptimized(std::vector<int>& nums) {
		int N = nums.size();

		std::vector<int> ans(N, 0);

		for (int i : std::views::iota(0, N)) {
			if (nums[i] & 1) {
				int z = ((nums[i]+1) & ~z) >> 1;
				ans[i] = nums[i] & ~z;
			} else {
				ans[i] = -1;
			}
		}

		return ans;
	}
}