#include <stack>

namespace monotonic_stack {

    class StockSpanner {
    private:
        std::stack<std::pair<int, int>> st;
        int currentIdx = 0;

    public:
        StockSpanner() {}
        
        int next(int price) {
            int res = 1;
            if (st.empty() || st.top().first > price) {
                st.push({price, currentIdx});
            } else {
                while (!st.empty() && price >= st.top().first) {
                    st.pop();
                }

                if (!st.empty()) {
                    res = currentIdx - st.top().second;
                } else {
                    res = currentIdx + 1;
                }

                st.push({price, currentIdx});
            }

            currentIdx += 1;
            return res;
        }
    };
}