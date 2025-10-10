#include <bits/stdc++.h>
using namespace std;

char change(char num){
    if(num=='0')return '1';
    else return '0';
}

int main() {
    int N,M;
    cin>>N>>M;
    int ans=0;
    vector<string>A(N);
    vector<string>B(N);
    
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
    for(int i=0; i<N; i++){
        cin>>B[i];
    }
    
    for(int i=0; i<N-2; i++){
        for(int j=0; j<M-2; j++){
            if(A[i][j]!=B[i][j]){
                A[i][j]=change(A[i][j]);A[i+1][j]=change(A[i+1][j]);A[i+2][j]=change(A[i+2][j]);
                A[i][j+1]=change(A[i][j+1]);A[i+1][j+1]=change(A[i+1][j+1]);A[i+2][j+1]=change(A[i+2][j+1]);
                A[i][j+2]=change(A[i][j+2]);A[i+1][j+2]=change(A[i+1][j+2]);A[i+2][j+2]=change(A[i+2][j+2]);
                ans++;
            }
        }
    }
    if(A==B)cout<<ans;
    else cout<<-1;
    return 0;
}