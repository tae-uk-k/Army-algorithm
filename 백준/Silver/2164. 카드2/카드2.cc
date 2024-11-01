#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    queue<int>card;
    cin>>N;
    
    for(int i=1;i<=N;i++){
        card.push(i);
    }
    
    while(card.size()!=1){
        card.pop();
        card.push(card.front());
        card.pop();
    }
    
    cout<<card.front();
    return 0;
}