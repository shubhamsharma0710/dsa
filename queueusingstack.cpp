#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> q; 
public:
    MyStack() { }
    
    void push(int x) {
        int size = q.size();
        q.push(x);
        
      
        while (size-- > 0) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if (q.empty()) {
            throw runtime_error("Pop operation on an empty stack");
        }
        int ret = q.front();
        q.pop();
        return ret;
    }
    
    int top() {
        if (q.empty()) {
            throw runtime_error("Top operation on an empty stack");
        }
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    cout << "Top element is: " << stack.top() << endl; 
    cout << "Stack is empty: " << stack.empty() << endl; 

    cout << "Popped element is: " << stack.pop() << endl; 
    cout << "Popped element is: " << stack.pop() << endl; 

    cout << "Top element is: " << stack.top() << endl; 

    stack.push(5);
    cout << "Top element is: " << stack.top() << endl; 

    return 0;
}
