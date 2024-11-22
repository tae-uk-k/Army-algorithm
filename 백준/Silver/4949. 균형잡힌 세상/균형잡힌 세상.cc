#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string a;
    while (true) {
        getline(cin, a);  
        if (a == ".") {
            return 0; 
        }

        stack<char> S; 
        bool isBalanced = true;

        for (char ch : a) {
            if (ch == '(' || ch == '[') {
                S.push(ch);
            } else if (ch == ')') {
                if (!S.empty() && S.top() == '(') {
                    S.pop();
                } else {
                    isBalanced = false;
                    break;
                }
            } else if (ch == ']') {
                if (!S.empty() && S.top() == '[') {
                    S.pop();
                } else {
                    isBalanced = false;
                    break;
                }
            }
        }
        if (isBalanced && S.empty()) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}
