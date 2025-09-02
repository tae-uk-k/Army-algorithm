#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;cin>>N;
    long long digit[6];
    for(int i=0; i<6; i++){
        cin>>digit[i];
    }
    if(N==1){
        long long m=min({
            digit[1]+digit[2]+digit[3]+digit[4]+digit[5],
            digit[0]+digit[2]+digit[3]+digit[4]+digit[5],
            digit[1]+digit[0]+digit[3]+digit[4]+digit[5],
            digit[1]+digit[2]+digit[0]+digit[4]+digit[5],
            digit[1]+digit[2]+digit[3]+digit[0]+digit[5],
            digit[1]+digit[2]+digit[3]+digit[4]+digit[0],
        });
        cout<<m;
        return 0;
    }
    long long face1,face2,face3;
    face1=min({digit[0],digit[1],digit[2],digit[3],digit[4],digit[5]});
    face2=min({
        digit[0]+digit[1],digit[0]+digit[2],digit[0]+digit[3],digit[0]+digit[4],
        digit[1]+digit[2],digit[1]+digit[3],digit[1]+digit[5],
        digit[2]+digit[5],digit[2]+digit[4],
        digit[3]+digit[4],digit[3]+digit[5],
        digit[4]+digit[5]});
    face3=min({
       digit[0]+digit[1]+digit[3],
       digit[0]+digit[2]+digit[4],
       digit[1]+digit[2]+digit[5],
       digit[3]+digit[4]+digit[5],
       digit[0]+digit[1]+digit[2],
       digit[0]+digit[4]+digit[3],
       digit[1]+digit[3]+digit[5],
       digit[2]+digit[4]+digit[5],
    });
    
    long long ans=0;
    ans+=face3*4;
    ans+=((N-1)*4+(N-2)*4)*face2;
    ans+=((N-1)*(N-2)*4+(N-2)*(N-2))*face1;
    cout<<ans;
    
    return 0;
}