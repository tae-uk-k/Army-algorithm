#include <iostream>
using namespace std;

int main() {
	int T,k,n;
	long long F[15][15];
	
	for(int k=1;k<15;k++){
	    F[0][k]=k;
	    F[k][0]=0;
	}
	
	cin>>T;
	
    for(int i = 1; i < 15; i++) {
        for(int j = 1; j < 15; j++) {
            F[i][j] = F[i-1][j] + F[i][j-1];
        }
    }
	
	for(int l=0;l<T;l++){
	    cin>>k>>n;
	    cout<<F[k][n]<<"\n";
	}
	
}
