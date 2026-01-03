#include <iostream>

class Solution {
public:
    int fibonacci(int n) { 
        return getFib(n, 0, 1); 
    }

    // using tail recursion
    int getFib(int n, int a, int b) {
        if (n == 0) return a;
        if (n == 1) return b;

        return getFib(n-1, b, a+b);
    }
};