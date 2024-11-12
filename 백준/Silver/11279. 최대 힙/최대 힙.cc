#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    priority_queue<int> pq;
    int N,O;
    cin>>N;
    
    for(int i=0; i<N; i++){
        cin>>O;
        if(O==0){
            if(pq.empty()){
                cout<<0<<"\n";
            }
            else{
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }
        else{
            pq.push(O);
        }
    }
    return 0;
}