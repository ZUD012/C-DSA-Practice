#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {
        // Constructor initializes empty stacks
    }

    // Push element x to the back of the queue
    void push(int x) {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        // Push the new element onto s1
        s1.push(x);
        // Move everything back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Removes the element from in front of the queue and returns it
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }

    // Get the front element
    int peek() {
        return s1.top();
    }

    // Return whether the queue is empty
    bool empty() {
        return s1.empty();
    }
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front element: " << q.peek() << endl; // 1
    cout << "Pop element: " << q.pop() << endl;   // 1
    cout << "Front element: " << q.peek() << endl; // 2
    q.pop();
    cout << "Front element: " << q.peek() << endl; // 3
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // No
    q.pop();
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Yes

    return 0;
}
