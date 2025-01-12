#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int firstMissingPositiveBrute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int next = 1;

        for (int num : nums) {
            if (num < 1) {
                continue;
            }

            if (next > num) {
                return next;
            } else {
                next += 1;
            }
        }
        return next;
    }

    int firstMissingPositiveHash(vector<int>& nums) {
        unordered_map<int, bool> m;

        for (int num : nums) {
            m[num] = true;
        }

        int next = 1;
        while(m[next]) {
            next += 1;
        }

        return next;
    }

    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();

        for (int i = 0; i < N; i++) {
            while (nums[i] > 0 && nums[i] <= N && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        int next = 1;
        for (int num : nums) {
            if (num != next) {
                return next;
            } else {
                next += 1;
            }
        }

        return next;
    }
};
