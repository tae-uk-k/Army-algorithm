#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    string S;
    cin>>S;
    
    vector<bool>s(7, false);
    vector<bool>b(7, false);
    for(char c : S){
        if(c=='R')b[0]=true;
        if(c=='r')s[0]=true;
        if(c=='O')b[1]=true;
        if(c=='o')s[1]=true;
        if(c=='Y')b[2]=true;
        if(c=='y')s[2]=true;
        if(c=='G')b[3]=true;
        if(c=='g')s[3]=true;
        if(c=='B')b[4]=true;
        if(c=='b')s[4]=true;
        if(c=='I')b[5]=true;
        if(c=='i')s[5]=true;
        if(c=='V')b[6]=true;
        if(c=='v')s[6]=true;
    }
    
    bool all =true;
    bool iss =true;
    bool isb =true;
    
    for(bool a : s){
        if(!a){
            all=false;
            iss=false;
        }
    }
    for(bool a : b){
        if(!a){
            all=false;
            isb=false;
        }
    }
    
    if(all)cout<<"YeS";
    else if(iss)cout<<"yes";
    else if(isb)cout<<"YES";
    else cout<<"NO!";
    return 0;
}







