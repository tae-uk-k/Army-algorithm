#include <bits/stdc++.h>
using namespace std;

vector<long long> tree;
int n;
int INF=1000000007;

void build(vector<long long>& arr, int v, int s, int e) {
    if(s==e) {
        tree[v]=arr[s];
    } 
    else {
        int mid=(s+e)/2;
        build(arr,2*v,s,mid);

        build(arr,2*v+1,mid+1,e);
        tree[v]=(tree[2*v]*tree[2*v+1])%INF;
    }
}

long long query(int v, int s, int e, int l, int r) {
    if(r<s||e<l) {
        return 1;
    }
    if(l<=s && e<=r) {
        return tree[v];
    }

    int mid=(s+e)/2;
    long long ls=query(2*v,s,mid,l,r);
    long long rs=query(2*v+1,mid+1,e,l,r);
    return (ls*rs)%INF;
}

void update(int v, int s, int e, int idx, long long x) {
    if(s==e) {
        tree[v]=x;
    } 
    else {
        int mid=(s+e)/2;

        if(idx<=mid) {
            update(2*v,s,mid,idx,x);
        } 
        else {
            update(2*v+1,mid+1,e,idx,x);
        }
        tree[v]=(tree[2*v]*tree[2*v+1])%INF;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m,k;cin>>n>>m>>k;
    vector<long long> arr(n);
    
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
    tree.resize(4*n);
    build(arr, 1, 0, n-1);

    for(int i=0; i<m+k; i++) {
        int a;cin>>a;
        
        if(a==1) {
            int b;
            long long c;
            cin>>b>>c;
            update(1,0,n-1,b-1,c);
        } 
        else {
            int b,c;
            cin>>b>>c;
            cout<<query(1,0,n-1,b-1,c-1)<<"\n";
        }
    }
    
    return 0;
}