#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;cin>>N;
    int num[N];
    int len[N];
    for(int i=0; i<N; i++){
        cin>>num[i];
    }
    
    for(int k=0; k<N; k++){
        len[k]=1;
        for(int j=0; j<k; j++){
            if(num[k]<num[j]){
                len[k]=max(len[k], len[j]+1);
            }
        }
    }
    
    int ans=0;
    for(int a : len){
        ans=max(a, ans);
    }
    cout<<ans;
    return 0;
}