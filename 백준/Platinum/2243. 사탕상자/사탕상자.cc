#include <bits/stdc++.h>
using namespace std;

vector<long long> tree;
const int MAX_TASTE = 1000000;
int n;
vector<int> leafNodes;  // 리프노드 번호들 저장

void build( int node, int start, int end) {
    if(start == end) {
        leafNodes.push_back(node);  // 리프노드 번호 저장
        tree[node] = 0;
    } else {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

pair<long long, int> query(int node, int start, int end, int k) {//시작노드를 받고 목표를 받고
    //일단 리프노드까ㅏ지는 가야함. 자식 노드가 없을 때 까지 재귀하기
    //왼쪽 오른쪽 자식중에서 왼쪽먼저 보고 목표보다 크면 왼쪽으로, 목표보다 작으면 오른쪼긍로 가기.
    //리프노드 도착하면 그 노드번호 반환하기.
    
    if(start == end) {
        // 리프노드 도착: {사탕맛번호, 노드번호} 반환
        return {start, node};
    }
    
    int mid = (start + end) / 2;
    long long leftSum = tree[2 * node];
    
    if(leftSum >= k) {
        return query(2 * node, start, mid, k);
    } else {
        return query(2 * node + 1, mid + 1, end, k - leftSum);
    }
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
        tree[v]=tree[2*v]+tree[2*v+1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    
    tree.resize(4*1000000);
    build(1, 1, MAX_TASTE);
    
    int A,B,C;
    for(int i=0; i<n; i++) {
        cin>>A;
        if(A==1){//사탕상자에서 사탕을 꺼내는 경우
            cin>>B;//꺼낼 사탕의 상자안에서 순위
            auto[candy, nodenum]=query(1,1,MAX_TASTE, B);//그 사탕이 있는 노드번호를 받았으니까 그 노드에서 -1하면 된다.
            update(1, 1, MAX_TASTE, candy, tree[leafNodes[candy-1]]-1);
            cout<<candy<<"\n";
        }
        else{
            cin>>B>>C;
            update(1, 1, MAX_TASTE, B, tree[leafNodes[B-1]]+C);
        }
    }

  
    
    return 0;
}