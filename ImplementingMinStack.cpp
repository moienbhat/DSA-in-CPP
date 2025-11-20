 #include<iostream>
 #include <stack>
#include <climits>
using namespace std;

class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int value) {
        long long val = value;
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val < mini) {
                st.push(2 * val - mini); // encode
                mini = val;
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long el = st.top();
        st.pop();

        if (el < mini) {
            // retrieve previous minimum
            mini = 2 * mini - el;
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long el = st.top();
        if (el < mini)
            return mini;
        return el;
    }

    int getMin() {
        return mini;
    }
};



int main() {
    MinStack minStack;
    minStack.push(5);
    minStack.push(2);
    minStack.push(0);
    minStack.push(1);
    minStack.push(-1);

    cout << "Top: " << minStack.top() << endl;      // -1
    cout << "Min: " << minStack.getMin() << endl;   // -1

    minStack.pop();
    cout << "Top after pop: " << minStack.top() << endl;    // 1
    cout << "Min after pop: " << minStack.getMin() << endl; // 0
}
