#include <bits/stdc++.h>
using namespace std;
const int INF=400000;
int main() {
    vector<int>DDR;
    int i;
    int cost[5][5] = {
        {0,  2,  2,  2,  2},
        {0,  1,  3,  4,  3}, 
        {0,  3,  1,  3,  4},  
        {0,  4,  3,  1,  3},  
        {0,  3,  4,  3,  1}   
    };
    while(cin>>i){
        if(i!=0)DDR.push_back(i);
    }
    vector<vector<vector<int>>>dp(DDR.size()+1, vector<vector<int>>(5, vector<int>(5, INF)));
    dp[0][0][0]=0;
    
    for(int j=0; j<DDR.size(); j++){
        int next=DDR[j];
        for(int l=0; l<5; l++){
            for(int r=0; r<5; r++){
                if(dp[j][l][r]==INF)continue;
                if(next!=r){
                    dp[j+1][next][r]=min(dp[j+1][next][r], dp[j][l][r]+cost[l][next]);
                }
                if(next!=l){
                    dp[j+1][l][next]=min(dp[j+1][l][next], dp[j][l][r]+cost[r][next]);
                }
            }
        }
    }
    
    int ans=INF;
    for(int l=0; l<5; l++){
        for(int r=0; r<5; r++){
            ans=min(ans, dp[DDR.size()][l][r]);
        }
    }
    cout<<ans;
    return 0;
}