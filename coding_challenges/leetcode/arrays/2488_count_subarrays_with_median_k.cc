#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        int countSubarrays(vector<int>& nums, int k) {
            int N = nums.size();
            unordered_map<int, int> count;
            count[0] = 1;
    
            bool includeK = false;
            int balance = 0;
    
            int ans = 0;
            for (int i = 0; i < N; i++) {
                if (nums[i] < k) 
                    balance -= 1;
                else if (nums[i] > k) 
                    balance += 1;
                else
                    includeK = true;
                
                if (includeK) {
                    ans += count[balance] + count[balance - 1];
                } else {
                    count[balance] += 1;
                }
            }
            return ans;
        }
    };