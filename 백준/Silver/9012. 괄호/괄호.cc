#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    string S;
    cin>>N;
    
    for(int i=0;i<N;i++){
        cin>>S;
        stack<char>p;
        stack<char>p2;
        
        for(char j: S){
            
            if(j=='('){
                p.push(j);
            }
            if(j==')'){
                if(p.empty()){
                    p2.push(j);
                }
                else{
                    p.pop();
                }
            }
        }
        if(p.empty()&&p2.empty()){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
    
    return 0;
}