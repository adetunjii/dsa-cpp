#include <string>
#include <vector>

namespace dp{
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        int N = s.length();

        std::vector<bool> dp(N+1, false);
        dp[0] = true;

        for (int i = 1; i <= N; i++) {
            for (std::string word : wordDict) {
                if (i >= word.length()) {
                    dp[i] = dp[i] || (s.substr(i-word.length(), word.length()) == word && dp[i-word.length()]);
                }
            }
        }

        return dp[N];
    }
}