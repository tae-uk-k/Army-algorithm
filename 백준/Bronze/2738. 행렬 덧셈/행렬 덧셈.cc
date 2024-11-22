#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N,M;
    cin>>N>>M;
    vector<vector<int>> A(N, vector<int>(M, 0));
    vector<vector<int>> B(N, vector<int>(M, 0));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>A[i][j];
        }
    }
    for(int k=0;k<N;k++){
        for(int l=0;l<M;l++){
            cin>>B[k][l];
        }
    }
    for(int o=0;o<N;o++){
        for(int p=0; p<M; p++){
            cout<<A[o][p]+B[o][p]<<' ';
        }
        cout<<endl;
    }
    return 0;
}