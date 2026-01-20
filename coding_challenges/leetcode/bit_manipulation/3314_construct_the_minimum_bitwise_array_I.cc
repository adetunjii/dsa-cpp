#include <vector>
#include <ranges>

namespace bitwiseOp{
	vector<int> minBitwiseArray(vector<int>& nums) {
		int N = nums.size();

		// 1001 being the maximum nums[i] there can be.
		int maxInt = 1001;
		std::vector<int> ans(N, maxInt);

		for (int i : std::views::iota(0, N)) {
			for (int j : std::views::iota(0, nums[i] + 1)) {
				if ((j | (j+1)) == nums[i]) {
					ans[i] = min(ans[i], j);
				}
			}

			// if after scanning, no number can be found, ans[i] = -1;
			if (ans[i] == maxInt) ans[i] = -1;
		}

		return ans;

	}	
}