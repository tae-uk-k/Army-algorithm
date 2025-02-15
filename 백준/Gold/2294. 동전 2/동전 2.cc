#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin>>n>>k;
    
    vector<long long>coin_sum(10001, INF);
    vector<int>coins;
    
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        coins.push_back(a);
    }
    
    coin_sum[0]=0;
    for(int j=0; j<=k; j++){
        for(int c : coins){
            if(j-c>=0){
                coin_sum[j]=min(coin_sum[j], coin_sum[j-c]+1);
            }
        }
    }
    if(coin_sum[k]==INF){
        cout<<-1;
        return 0;
    }
    cout<<coin_sum[k];
    return 0;
}