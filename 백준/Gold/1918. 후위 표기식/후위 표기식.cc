#include <bits/stdc++.h>
using namespace std;
int main() {
    string S;
    cin>>S;
    stack<char>st;
    int parentheses=0;
    for(int i=0; i<S.size(); i++){
        char s=S[i];
        if (s >= 'A' && s <= 'Z'){
            cout<<s;
            continue;
        }
        if(s=='('){
            st.push(s);
            parentheses++;
        }
        else if (s == ')') {
            parentheses--;
            while (st.top() != '(') {
                cout<<st.top();
                st.pop();
            }
            st.pop();
        }
        else if((s=='+'||s=='-')&&!st.empty()&&(st.top()=='*'||st.top()=='/')){
            while(!st.empty()&&st.top()!='('){
                cout<<st.top();
                st.pop();
            }
            st.push(s);
        }
        else if((s=='+'||s=='-')&&!st.empty()&&(st.top()=='+'||st.top()=='-')){
            while(!st.empty()&&st.top()!='('&&(st.top()=='+'||st.top()=='-'||st.top()=='*'||st.top()=='/')){
                cout<<st.top();
                st.pop();
            }
            st.push(s);
        }
        else if((s=='*'||s=='/')&&!st.empty()&&(st.top()=='*'||st.top()=='/')){
            while(!st.empty()&&st.top()!='('&&(st.top()=='*'||st.top()=='/')){
                cout<<st.top();
                st.pop();
            }
            st.push(s);
        }
        else {
            st.push(s);
        }
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    return 0;
}