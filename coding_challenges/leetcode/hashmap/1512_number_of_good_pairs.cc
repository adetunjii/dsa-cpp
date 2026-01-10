#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int, int> m;
        int res = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (nums[i] == nums[j]) res += 1;
            }
        }

        return res;
    }

    int numIdenticalPairsAlternate(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int, int> m;
        int res = 0;
        for (int i = 0; i < N; i++)  {
            m[nums[i]] += 1;
        }       

        for (const auto& [key, value] : m) {
            res += value * (value - 1) / 2;
        }

        return res;
    }
};