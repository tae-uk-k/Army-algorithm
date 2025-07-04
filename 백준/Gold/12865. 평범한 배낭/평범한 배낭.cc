#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;

int main() {
    int N,K;
    cin>>N>>K;
    
    vector<int>MAX_value(K+1,0);
    vector<pair<int,int>>weight_value;//무게가 앞 가치가 뒤
    MAX_value[0]=0;
    
    for(int i=0; i<N; i++){
        int a,b;
        cin>>a>>b;
        weight_value.push_back({a,b});
    }
    
    for(int k=0; k<weight_value.size(); k++){
        auto[w,v]=weight_value[k];
        for(int j=K; j>=w; j--){  // 역순으로!
            if(MAX_value[j-w]!=INF){
                MAX_value[j]=max(MAX_value[j], MAX_value[j-w]+v);
            }
        }
    }
    
    cout<<MAX_value[K];
    return 0;
}