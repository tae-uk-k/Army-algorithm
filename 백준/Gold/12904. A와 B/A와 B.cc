#include <bits/stdc++.h>
using namespace std;

int main() {
    string S,T;
    cin>>S>>T;
    
    while(S.size()!=T.size()){
        if(T.back()=='B'){
            T.pop_back();
            reverse(T.begin(), T.end());
            continue;
        }
        if(T.back()=='A')T.pop_back();
    }
    
    if (S== T) cout << 1;
    else cout<<0;
    return 0;
}