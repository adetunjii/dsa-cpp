#include <string>
#include <vector>

namespace dp {
int numDecodings(std::string s) {
    int N = s.length();

    if (N == 0) return 0;
    if (s[0] == '0') return 0;

    std::vector<int> dp(N+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        if (s[i] != '0') dp[i] += dp[i-1];
        int num = (s[i-1] - '0') * 10 + (s[i] - '0');
        if (10 <= num && num <= 26) {
            dp[i] += dp[i-2];
        }
    }

    return dp[N];
}
}