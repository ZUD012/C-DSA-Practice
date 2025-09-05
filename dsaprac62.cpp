#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s) {
    stack<char> st ;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            // Opening case
            st.push(s[i]);
        }
        else { // Closing bracket case
            if (st.empty()) {
                return false;
            }
            if ((st.top() == '(' && s[i] == ')') ||
                (st.top() == '[' && s[i] == ']') ||
                (st.top() == '{' && s[i] == '}')) {
                st.pop();
            }
            else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string s1 = "({[]})";
    string s2 = "([)]";
    string s3 = "()[]{}";
    string s4 = "(((";

    cout << s1 << " -> " << (isValid(s1) ? "Valid" : "Invalid") << endl;
    cout << s2 << " -> " << (isValid(s2) ? "Valid" : "Invalid") << endl;
    cout << s3 << " -> " << (isValid(s3) ? "Valid" : "Invalid") << endl;
    cout << s4 << " -> " << (isValid(s4) ? "Valid" : "Invalid") << endl;

    return 0;
}
