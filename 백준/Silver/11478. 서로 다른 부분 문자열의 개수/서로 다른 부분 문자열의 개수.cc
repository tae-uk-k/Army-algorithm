#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    set<string> s;
    string S;
    cin>>S;
    
    for(int i=1; i<=S.size(); i++){
        int length=i;
        int start=0;
        while(start+length<=S.size()){
            string sliced_str = S.substr(start, length);
            s.insert(sliced_str);
            start++;
        }
    }
    cout<<s.size();
}