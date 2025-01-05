#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int N = nums.size();
        int max_count = nums.size() / 2; 

        unordered_map<int, int> m;
        int max = 0;

        for (int i = 0; i < N; i++) {
            m[nums[i]] += 1;
        }

        for (const auto& [key, value] : m) {
            if (value > max_count && value > max) {
                max = key;
            }
        }
        return max;
    }

    int majorityElementOptimal(vector<int>& nums) {
        int count = 0, candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }

            if (candidate == num) {
                count += 1;
            } else {
                count -= 1;
            }
        }
        return candidate;
    }
};