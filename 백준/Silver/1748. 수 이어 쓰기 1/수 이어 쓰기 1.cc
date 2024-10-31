#include <bits/stdc++.h>

using namespace std;

int main() {
    string N;
    long long N2;
    cin>>N;
    N2=stoll(N);
    if(N.size()==9){
        cout<<788888898;
    }
    if(N.size()==8){
        N2-=9999999;
        cout<<N2*8+68888889;
    }
    if(N.size()==7){
        N2-=999999;
        cout<<N2*7+5888889;
    }
    if(N.size()==6){
        N2-=99999;
        cout<<N2*6+486889;
    }
    if(N.size()==5){
        N2-=9999;
        cout<<N2*5+38889;
    }
    if(N.size()==4){
        N2-=999;
        cout<<N2*4+2889;
    }
    if(N.size()==3){
        N2-=99;
        cout<<N2*3+189;
    }
    if(N.size()==2){
        N2-=9;
        cout<<N2*2+9;
    }
    if(N.size()==1){
        cout<<N2;
    }
    return 0;
}