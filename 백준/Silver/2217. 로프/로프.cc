#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, rope;
    int max=0;
    vector<int>ropes;
    
    cin>>N;
    
    for(int i=0;i<N;i++){
        cin>>rope;
        ropes.push_back(rope);
    }
    
    sort(ropes.begin(), ropes.end());
    max=ropes[0]*ropes.size();
    
    for(int j=1;j<ropes.size();j++){
        if(ropes.size()==1){
            cout<<ropes[0];
            return 0;
        }
        if(max<ropes[j]*(ropes.size()-j)){
            max=ropes[j]*(ropes.size()-j);
        }
    }
    
    cout<<max;
    
    return 0;
}