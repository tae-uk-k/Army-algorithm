#include <bits/stdc++.h>
using namespace std;

int main() {
    int count = 0;
    char a, prev = 0;
    stack<char> P;
    
    while (cin >> a) {
        if (a == '(') {
            P.push(a);
        } else if (a == ')' && !P.empty()) {
            if (prev == '(') {  
                P.pop(); 
                count += P.size();  
            } else { 
                P.pop();  
                count += 1; 
            }
        }
        prev = a; 
    }
    cout << count;
    
    return 0;
}
