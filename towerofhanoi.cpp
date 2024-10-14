#include <iostream>
using namespace std;

#define MAX 1000

class Stack {
    int top;
    int arr[MAX];

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    void push(int x) {
        if (top >= (MAX - 1)) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return arr[top];
    }
};

void moveDisk(char from, char to, int disk) {
    cout << "Move disk " << disk << " from rod " << from << " to rod " << to << endl;
}

void towerOfHanoi(int n) {
    Stack source, destination, auxiliary;

    for (int i = n; i >= 1; --i) {
        source.push(i);
    }

    char s = 'A', d = 'C', a = 'B';
    int numMoves = (1 << n) - 1;  

    for (int i = 1; i <= numMoves; ++i) {
        if (i % 3 == 1) {
            int disk = source.pop();
            destination.push(disk);
            moveDisk(s, d, disk);
        } else if (i % 3 == 2) {
            int disk = source.pop();
            auxiliary.push(disk);
            moveDisk(s, a, disk);
        } else if (i % 3 == 0) {
            int disk = auxiliary.pop();
            destination.push(disk);
            moveDisk(a, d, disk);
        }
    }
}

int main() {
    int n = 3;  
    towerOfHanoi(n);
    return 0;
}

