#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int sum=0;
    int N;
    cin>>N;
    vector<int>tree;
    for(int i=0; i<N; i++){
        int a;
        cin>>a;
        tree.push_back(a);
    }
    int del;
    cin>>del;
    tree[del]=-2;
    queue<int>q;
    q.push(del);
    while(!q.empty()){
        for(int j=0; j<N; j++){
            int m=tree[j];
            if(m==q.front()){
                tree[j]=-2;
                q.push(j);
            }
        }
        q.pop();
    }
    for(int k=0; k<N; k++){
        if(tree[k]==-2)continue;
        if(find(tree.begin(), tree.end(), k)==tree.end())sum++;
    }
    cout<<sum;
    return 0;
}






