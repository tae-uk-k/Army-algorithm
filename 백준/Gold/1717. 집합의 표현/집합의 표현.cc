#include <bits/stdc++.h>
using namespace std;

int parent[1000001];
int rankArr[1000001];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    
    if (rootX != rootY) {
        if (rankArr[rootX] < rankArr[rootY]) {
            parent[rootX] = rootY;
        } else if (rankArr[rootX] > rankArr[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rankArr[rootX]++;
        }
    }
}

bool isConnected(int x, int y) {
    return find(x) == find(y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin >>n>>m;
    
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        rankArr[i] = 0;
    }
    for(int j=0; j<m; j++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==0){
             unionSet(b,c);
        }
        if(a==1){
            if(find(b)==find(c))cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }
    }

    
    return 0;
}