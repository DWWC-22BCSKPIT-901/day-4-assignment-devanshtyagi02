#include <iostream>
#include <stack>
#include <string>
using namespace std;

string isBalanced(string s) {
    stack<char> bracketStack;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            bracketStack.push(c);
        } else {
            if (bracketStack.empty()) {
                return "NO";
            }

            char top = bracketStack.top();
            if ((c == ')' && top == '(') || (c == '}' && top == '{') || (c == ']' && top == '[')) {
                bracketStack.pop();
            } else {
                return "NO";
            }
        }
    }

    return bracketStack.empty() ? "YES" : "NO";
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        cout << isBalanced(s) << endl;
    }
    return 0;
}