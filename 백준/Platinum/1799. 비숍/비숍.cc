#include <bits/stdc++.h>
using namespace std;

int N;
int WB_sum[2];
int board[11][11];
int l[20];
int r[20];

void BT(int x, int y, int sum, int color){
    if(y>=N){
        x++;
        if(y%2 ==0) y=1;
        else y=0;
    }
    if(x>=N){
        WB_sum[color]= (WB_sum[color]>sum) ? WB_sum[color]:sum;
        return;
    }
    
    if(board[x][y]==1 && !l[y-x+N] && !r[x+y]){
        l[y-x+N]=r[x+y]=1;
        BT(x,y+2,sum+1,color);
        l[y-x+N]=r[x+y]=0;
    }
    BT(x,y+2,sum,color);
}

int main() {
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>board[i][j];
        }
    }
    
    BT(0,0,0,0);
    BT(0,1,0,1);
    
    cout<<WB_sum[0]+WB_sum[1];
    return 0;
}










