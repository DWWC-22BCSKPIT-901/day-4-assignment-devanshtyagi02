#include <stack>
#include <stdexcept>
#include<iostream>

class MinStack {
private:
    std::stack<int> stack;
    std::stack<int> minStack; 

public:
    MinStack() {
    }

    void push(int val) {
        stack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (stack.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        if (stack.top() == minStack.top()) {
            minStack.pop();
        }
        stack.pop();
    }

    int top() {
        if (stack.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return stack.top(); 
    }

    int getMin() {
        if (minStack.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return minStack.top();
    }
};

 int main() {
     MinStack minStack;
     minStack.push(-2);
     minStack.push(0);
     minStack.push(-3);
     std::cout << minStack.getMin() << std::endl; 
     minStack.pop();
     std::cout << minStack.top() << std::endl;  
     std::cout << minStack.getMin() << std::endl; 
     return 0;
 }