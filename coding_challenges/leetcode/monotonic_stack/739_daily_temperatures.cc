#include <vector>
#include <stack>

namespace monotonic_stack {
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        const int N = temperatures.size();
        if (N == 0) return {};

        std::vector<int> answer(N, 0);
        
        int hottest = 0;

        for (int i = N - 1; i >= 0; --i) {
            int currentTemp = temperatures[i];

            if (currentTemp >= hottest) {
                hottest = currentTemp;
                continue;
            }

            int days = 1;
            while (temperatures[i + days] <= currentTemp) { // skip colder days
                days += answer[i+days];
            }

            answer[i] = days;
        }

        return answer;
    }
}