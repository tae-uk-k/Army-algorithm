#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    string name;
    string access_or_not;
    cin>>N;
    map<string, string, greater<string>>access_log;
    for(int i=0;i<N;i++){
        cin>>name;
        cin>>access_or_not;
        access_log[name]=access_or_not;
    }
    for (const auto& pair : access_log) {
        if(pair.second=="enter"){
            cout<<pair.first<<"\n";
        }
    }
    return 0;
}