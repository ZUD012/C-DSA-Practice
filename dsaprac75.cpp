#include<iostream>
#include<queue>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
        // Constructor initializes empty queues
    }

    // Push element x onto stack
    void push(int x) {
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // Push the new element into q1
        q1.push(x);
        // Move everything back from q2 to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    // Removes the element on top of the stack and returns it
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    // Get the top element
    int top() {
        return q1.front();
    }

    // Return whether the stack is empty
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack s;
    
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl; // 30
    cout << "Pop element: " << s.pop() << endl; // 30
    cout << "Top element: " << s.top() << endl; // 20
    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl; // No
    s.pop();
    s.pop();
    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl; // Yes

    return 0;
}
