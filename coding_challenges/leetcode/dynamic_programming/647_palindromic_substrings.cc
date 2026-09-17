#include <string>
namespace dp{
int countSubstrings(std::string s) {
    auto expand = [&](int l, int r) {
        int count = 0;
        while ((0 <= l) && (r < s.length())) {
            if (s[l] != s[r]) break;
            count += 1;
            l -= 1;
            r += 1;
        }

        return count;
    };

    int result = 0;

    for (int i = 0; i < s.length(); i++) {
        result += expand(i, i);
        result += expand(i, i+1);
    }

    return result;
}
}