#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, num;
    long long S[501][501];
    
    cin>>N;
    
    for(int i=1;i<N+1;i++){
        for(int j=1;j<i+1;j++){
            cin>>num;
            S[i][j]=num;
        }
    }
    
    for(int a=N-1;a>0;a--){//여기서 a는 층을 의미
        for(int b=1;b<a+1;b++){
            S[a][b]=max(S[a+1][b],S[a+1][b+1])+S[a][b];
        }
    }
    
    cout<<S[1][1];
}