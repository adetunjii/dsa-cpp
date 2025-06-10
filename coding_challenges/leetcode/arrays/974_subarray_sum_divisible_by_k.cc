#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int N = nums.size();
        int count = 0;
        unordered_map<int, int> m;
        int sum = 0;
        m[0] = 1;
        for (int i = 0; i < N; i++) {
            sum += nums[i];
            int rem = ((sum % k) + k) % k; // modulo normalisation operation (negative modulos are bad)
            if (m.find(rem) != m.end())
                count += m[rem];
            m[rem] += 1;
        }

        return count;
    }
};