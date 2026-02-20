#include <vector>
#include <stack>
#include <string>

namespace stack {
        int calculate(std::string s) {
            int N = s.size();

            if(N == 0) return 0;

            std::stack<int> st;
            
            auto isOperator = [](char op) -> bool {
                return op == '*' || op == '/' || op == '+' || op == '-';
            };

            int i = 0;
            char op = '+';
            
            while (i < N) {
                if (s[i] == ' ') {
                    i += 1;
                } else if (isOperator(s[i])) {
                    op = s[i];
                    i += 1;
                } else {
                    int num = 0;

                    while (i < N && isdigit(s[i])) {
                        num = (num * 10) + (s[i] - '0');
                        i += 1;
                    }

                    if (op == '*' || op == '/') {
                        int x = st.top();
                        st.pop();
                        (op == '*') ? st.push(num * x) : st.push(x/num);
                    } else if (op == '+') {
                        st.push(num);
                    } else {
                        st.push(num * -1);
                    }
                }
            }

            int res = 0;
            while (!st.empty()) {
                res += st.top();
                st.pop();
            }

            return res;
        }
}