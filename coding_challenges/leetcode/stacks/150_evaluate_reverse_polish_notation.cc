#include <vector>
#include <string>
#include <stack>

namespace stack {
    int evalRPN(std::vector<std::string>& tokens) {
        int N = tokens.size();

        if (N == 0) return 0;

        std::stack<int> st;

        auto execOp = [](int A, int B, std::string& op) -> int {
            if (op == "+") {
                return A + B;
            } else if (op == "-") {
                return A - B;
            } else if (op == "*") {
                return A * B;
            } else if (op == "/") {
                return (int) A / B;
            } else {
                return 0;
            }
        };

        for (std::string& token : tokens) {
            if (token == "*" || token == "/" || token == "+" || token == "-") {
                int B = st.top();
                st.pop();
                int A = st.top();
                st.pop();
                
                int res = execOp(A, B, token);

                st.push(res);
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
}