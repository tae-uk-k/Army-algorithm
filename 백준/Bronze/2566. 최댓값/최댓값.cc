#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    int t;
    priority_queue<tuple<int,int,int>>pq;
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            cin>>t;
            pq.push({t,i,j});
        }
    }
    auto[a,b,c] = pq.top();
    cout<<a<<"\n"<<b<<' '<<c;
    return 0;
}