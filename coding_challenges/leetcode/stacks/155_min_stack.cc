#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> st, mn;
    int N;
public:
    MinStack() {
    }
    
    void push(int val) {      
        if (st.empty()) {
            st.push(val);
            mn.push(val);
        } else {
            st.push(val);
            mn.push(min(mn.top(), val));
        }
    }
    
    void pop() {
        st.pop();
        mn.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mn.top();
    }
};
