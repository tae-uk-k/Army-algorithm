#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N,A;
    cin>>N;
    
    stack<int>stor;
    stack<int>comp;
    stack<int>result;
    vector<int>num(1000001, 0);
    
    for(int i=0; i<N; i++){
        cin>>A;
        stor.push(A);
        num[A]++;
    }
    
    while(!stor.empty()){
        
        while(!comp.empty()&&num[stor.top()]>=num[comp.top()]){
            comp.pop();
        }
        
        if(comp.empty()){
            result.push(-1);
        }
        else{
            result.push(comp.top());
        }
        
        comp.push(stor.top());
        stor.pop();
    }
    
    while(!result.empty()){
        cout<<result.top()<<' ';
        result.pop();
    }
    return 0;
}