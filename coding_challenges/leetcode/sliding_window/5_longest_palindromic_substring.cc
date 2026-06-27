#include <string>

std::string longestPalindrome(std::string s) {
    int N = s.size();

    if (N <= 1)
        return s;

    int maxLength = 0;
    int startIndex = 0;

    auto isPalindrome = [&](int left, int right) {
        while (left >= 0 && right < N && s[left] == s[right]) {
            if ((right - left + 1) > maxLength) {
                maxLength = right - left + 1;
                startIndex = left;
            }

            left -= 1;
            right += 1;
        }
    };

    for (int i = 0; i < N - 1; i++) {
        isPalindrome(i, i);
        isPalindrome(i, i + 1);
    }

    return s.substr(startIndex, maxLength);
}