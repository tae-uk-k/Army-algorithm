#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    priority_queue<int,vector<int>,greater<int>>N_num;
    int N;
    cin>>N;
    int num;
    for(int i=0;i<N;i++){
        cin>>num;
        N_num.push(num);
    }
    
    while(cin>>num){
        N_num.push(num);
        N_num.pop();
    }
    cout<<N_num.top();
}