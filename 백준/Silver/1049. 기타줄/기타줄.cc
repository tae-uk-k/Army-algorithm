#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,M;cin>>N>>M;
    priority_queue<int, vector<int>, greater<int>>pq;
    priority_queue<int, vector<int>, greater<int>>packs;
    priority_queue<int, vector<int>, greater<int>>eachs;
    
    for(int i=0; i<M; i++){
        int pack, each;
        cin>>pack>>each;
        packs.push(pack);
        eachs.push(each);
    }
    int p=packs.top();
    int e=eachs.top();
    pq.push(e*N);//낱개만으로 살 때
    pq.push(p*(N/6+1));//패키지로 다 실 때
    pq.push(p*(N/6)+e*(N%6));//패키지로 사고 나머지 낱개로 살 때     
    
    cout<<pq.top();
    return 0;
}