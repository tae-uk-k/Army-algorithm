#include <bits/stdc++.h>
using namespace std;

struct CompareByAbsoluteValue {
    bool operator()(int a, int b) {
        if (std::abs(a) == std::abs(b)) {
            return a > b;
        }
        return std::abs(a) > std::abs(b);
    }
};


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    std::priority_queue<int, std::vector<int>, CompareByAbsoluteValue> pq;
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