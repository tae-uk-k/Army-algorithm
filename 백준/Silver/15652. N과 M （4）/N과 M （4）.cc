#include<bits/stdc++.h>
using namespace std;



int N,M;

void BT(int level,int selected, vector<int>save){
    
    if(level==M){
        for(int s : save){
            cout<<s<<' ';
        }
        cout<<"\n";
        return;
    }
    for(int i=selected; i<=N; i++){
        save.push_back(i);
        BT(level+1,i, save);
        save.pop_back();
    }
}

int main(){
    
    cin>>N>>M;
    vector<int>save;
    BT(0,1, save);
    
    
}