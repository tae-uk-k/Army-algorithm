#include <bits/stdc++.h>//56
using namespace std;

int main() {
    int N;
    cin>>N;
    long long sum=0;
    stack<int>s;
    int a;
    for(int i=0; i<N; i++){
        cin>>a;
        s.push(a);
    }
    int min=s.top();
    sum+=s.top();
    s.pop();
    while(!s.empty()){
        int now=s.top();
        s.pop();
        if(now>=min){
            sum+=min;
        }
        else if(now<min){
            min=now;
            sum+=min;
        }
        
    }
    cout<<sum;
    return 0;
}