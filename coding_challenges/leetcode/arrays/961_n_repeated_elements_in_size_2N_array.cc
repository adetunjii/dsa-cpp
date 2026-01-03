#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        // a hashmap would work as well. The major advantage to this is that space used is constant.
        int N = 1e4;
        std::vector<int> vec(N, -1);

        for (int i = 0; i < nums.size(); i++)
        {
            if (vec[nums[i]] == nums[i])
            {
                return nums[i];
            }

            vec[nums[i]] = nums[i];
        }

        return -1;
    }
};