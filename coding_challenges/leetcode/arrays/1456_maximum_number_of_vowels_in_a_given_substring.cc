#include <ranges>
#include <string>

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int maxVowels(std::string s, int k) {
    int N = s.size();
    int count = 0;
    for (int i : std::views::iota(0, k)) {
        if (isVowel(s[i])) {
            count += 1;
        }
    }

    int maxCount = count;

    for (int i : std::views::iota(k, N)) {
        if (isVowel(s[i - k])) {
            count -= 1;
        }

        if (isVowel(s[i])) {
            count += 1;
        }

        if (count > maxCount) {
            maxCount = count;
        }
    }

    return maxCount;
}