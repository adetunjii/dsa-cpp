#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

class Solution {
public: 
    bool isHappyRecursive(int n) {
        unordered_set<int> s;
        return isValid(n, s);
    }

    bool isValid(int n, unordered_set<int> s) {
        if (n == 1) return true;

        int sum = 0;
        while(n > 0) {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        if (sum == 1) return true;
        if (s.count(sum) > 0) return false;

        s.insert(sum);
        isValid(sum, s);
    }

    bool isHappy(int n) {
        if (n == 1) return false;
        unordered_set<int> s;
        while(s.find(n) == s.end()) {
            s.insert(n);

            int sum = 0;
            while(n > 0) {
                sum = pow(n%10, 2);
                n /= 10;
            }
            n = sum;
            if (n == 1) return true;
        }
        return false;
    }
};