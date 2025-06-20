#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;
    vector<vector<string>> paths(N);
    for(int i=0;i<N;i++){
        int K;
        cin>>K;
        paths[i].resize(K);
        for(int j=0;j<K;j++){
            cin>>paths[i][j];
        }
    }
    sort(paths.begin(),paths.end());
    vector<string> prev;
    for(const auto& path:paths){
        int lcp=0;
        while(lcp<prev.size()&&lcp<path.size()&&prev[lcp]==path[lcp]) lcp++;
        for(int i=lcp;i<path.size();i++){
            for(int d=0;d<i;d++) cout<<"--";
            cout<<path[i]<<'\n';
        }
        prev=path;
    }
    return 0;
}
