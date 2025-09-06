#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

class Minstack {
public:
    stack<pair<int,int>> s;

    Minstack() {
        // Constructor can be empty
    }

    void push(int val) {
        if(s.empty()) {
            s.push({val, val});
        } else {
            int minval = min(val, s.top().second);
            s.push({val, minval});
        }
    }

    void pop() {
        if(!s.empty())
            s.pop();
    }

    int top() {
        if(!s.empty())
            return s.top().first;
        return -1; // or throw an exception
    }

    int getMin() {
        if(!s.empty())
            return s.top().second;
        return -1; // or throw an exception
    }
};

int main() {
    Minstack minStack;
    minStack.push(3);
    minStack.push(5);
    cout << "Top: " << minStack.top() << endl;        // 5
    cout << "Min: " << minStack.getMin() << endl;     // 3
    minStack.push(2);
    minStack.push(1);
    cout << "Min: " << minStack.getMin() << endl;     // 1
    minStack.pop();
    cout << "Min: " << minStack.getMin() << endl;     // 2
    minStack.pop();
    cout << "Top: " << minStack.top() << endl;        // 5
    cout << "Min: " << minStack.getMin() << endl;     // 3
    return 0;
}
