#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge_brute(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = m + n - 1;
        while (--n >= 0) {
            nums1[l] = nums2[n];
            l -= 1;
        }

        sort(nums1.begin(), nums1.end());
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while (n > 0) {
            if (m == 0 || nums2[n-1] > nums1[m-1]) {
                nums1[m+n-1] = nums2[n-1];
                n -= 1;
            } else if (nums1[m-1] >= nums2[n-1]) {
                nums1[m+n-1] = nums1[m-1];
                m -= 1;
            }
        }
    }
};