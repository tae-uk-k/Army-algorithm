#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;cin>>N;
    int coin[4]={25,10,5,1};
    for(int i=0; i<N; i++){
        int change;
        cin>>change;

        int ans[4]={};
        while(change!=0){
            for(int j=0; j<4; j++){
                if(change-coin[j]>=0){
                    change -= coin[j];
                    ans[j]++;
                    break;
                }
            }
        }
        for(int a : ans){
            cout<<a<<' ';
        }
        cout<<"\n";
    }
    return 0;
}