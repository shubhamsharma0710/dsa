#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class MinStack {
    stack<int> s;
    stack<int> s_min; 
    int min = INT_MAX;

public:
    MinStack() { }

    void push(int val) {
        if (val <= min) {
            s_min.push(val);
            min = val;
        }
        s.push(val);
    }

    void pop() {
        if (s.empty()) {
            throw runtime_error("Pop operation on an empty stack");
        }
        if (s.top() == s_min.top()) {
            s_min.pop();
            min = s_min.empty() ? INT_MAX : s_min.top();
        }
        s.pop();
    }

    int top() {
        if (s.empty()) {
            throw runtime_error("Top operation on an empty stack");
        }
        return s.top();
    }

    int getMin() {
        if (s_min.empty()) {
            throw runtime_error("GetMin operation on an empty stack");
        }
        return min;
    }

    bool empty() {
        return s.empty();
    }
};

int main() {
    MinStack minStack;
    minStack.push(5);
    minStack.push(2);
    minStack.push(3);
    minStack.push(1);

    cout << "Minimum element: " << minStack.getMin() << endl; 
    cout << "Top element: " << minStack.top() << endl;

    minStack.pop();
    cout << "Minimum element after pop: " << minStack.getMin() << endl; 
    cout << "Top element after pop: " << minStack.top() << endl;

    return 0;
}
