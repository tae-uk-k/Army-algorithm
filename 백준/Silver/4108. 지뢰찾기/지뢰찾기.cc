#include <bits/stdc++.h>
using namespace std;

void add(int j, int k, int X, int Y, vector<vector<int>>& count){
    if(j+1<X)count[j+1][k]++;
    if(j-1>=0)count[j-1][k]++;
    if(k+1<Y)count[j][k+1]++;
    if(k-1>=0)count[j][k-1]++;
    
    if(j+1<X&&k+1<Y)count[j+1][k+1]++;
    if(j+1<X&&k-1>=0)count[j+1][k-1]++;
    if(j-1>=0&&k+1<Y)count[j-1][k+1]++;
    if(j-1>=0&&k-1>=0)count[j-1][k-1]++;
}

int main() {
    int X,Y;
    while(cin>>X>>Y){
        if(X==0&&Y==0)return 0;
        vector<string>ground(X);
        vector<vector<int>>count(X, vector<int>(Y,0));
        for(int i=0; i<X; i++){
            cin>>ground[i];
        }
        for(int j=0; j<X; j++){
            for(int k=0; k<Y; k++){
                if(ground[j][k]=='.')continue;
                else{
                    count[j][k]=-987654321;
                    add(j,k,X,Y,count);
                }
            }
        }
        
        for(int j=0; j<X; j++){
            for(int k=0; k<Y; k++){
                if(count[j][k]<0)cout<<'*';
                else cout<<count[j][k];
            }
            cout<<"\n";
        }
    }
    return 0;
}







