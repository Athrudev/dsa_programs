#include <iostream>
#include <stack>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

// Node structure for singly linked list
struct Node {
    char data;
    Node* next;
};

// Stack as an ADT using a singly linked list
class Stack {
private:
    Node* top;

public:
    Stack(){
        top=nullptr;
    }

    void push(char value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return '\0';
        }
        Node* temp = top;
        char value = temp->data;
        top = top->next;
        delete temp;
        return value;
    }

    char peek() {
        if(isEmpty()){
            return '\0';
        }else{
            return top->data;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

// Helper functions for conversion and evaluation
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string infixToPostfix(string infix) {
    Stack stack;
    string postfix;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.pop();
            }
            stack.pop(); // Remove '('
        } else if (isOperator(c)) {
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(c)) {
                postfix += stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }

    return postfix;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    for (char& c : infix) {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }

    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int evaluatePostfix(string postfix) {
    stack<int> stack;

    for (char c : postfix) {
        if (isdigit(c)) {
            stack.push(c - '0');
        } else if (isOperator(c)) {
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            switch (c) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': stack.push(a / b); break;
            }
        }
    }

    return stack.top();
}

int evaluatePrefix(string prefix) {
    stack<int> stack;
    reverse(prefix.begin(), prefix.end());

    for (char c : prefix) {
        if (isdigit(c)) {
            stack.push(c - '0');
        } else if (isOperator(c)) {
            int a = stack.top(); stack.pop();
            int b = stack.top(); stack.pop();
            switch (c) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': stack.push(a / b); break;
            }
        }
    }

    return stack.top();
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    string prefix = infixToPrefix(infix);
    cout << "Prefix: " << prefix << endl;

    cout << "Postfix Evaluation: " << evaluatePostfix(postfix) << endl;
    cout << "Prefix Evaluation: " << evaluatePrefix(prefix) << endl;

    return 0;
}