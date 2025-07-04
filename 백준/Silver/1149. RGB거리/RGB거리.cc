#include <bits/stdc++.h>
using namespace std;
int INF=987654321;

int main() {
    int N;cin>>N;
    int RGB[1001][3];
    int ans[1001][3];
    ans[0][0]=ans[0][1]=ans[0][2]=0;
    for(int i=1; i<=N; i++){
        for(int j=0; j<3; j++){
            cin>>RGB[i][j];
        }
    }
    for(int k=1; k<=N; k++){
        ans[k][0]=RGB[k][0]+min(ans[k-1][1], ans[k-1][2]);
        ans[k][1]=RGB[k][1]+min(ans[k-1][0], ans[k-1][2]);
        ans[k][2]=RGB[k][2]+min(ans[k-1][1], ans[k-1][0]);
    }
    cout<< min({ans[N][0], ans[N][1], ans[N][2]});
    return 0;
}