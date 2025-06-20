#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;

int main() {
    int N,K;
    cin>>N>>K;
    int size=N;

    if(N>=K){
        cout<<N-K;
        return 0;
    }
    if (N == 0) size = 1;
    while(size<K){
        size*=2;
    }

    if (N > 0 && size == K) {
        cout<<0;
        return 0;
    }

    vector<int> dist(size+1, INF);
    dist[N]=0;

    priority_queue< pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>> > pq;

    pq.push({0, N});

    while(!pq.empty()){
        auto [time_sum, now_node] = pq.top();
        pq.pop();

        if (dist[now_node] < time_sum) continue;

        int nextCost = time_sum + 1;
        if (now_node+1 <= size && nextCost < dist[now_node+1]) {
            dist[now_node+1] = nextCost;
            pq.push({nextCost, now_node+1});
        }
        if (now_node-1 >= 0 && nextCost < dist[now_node-1]) {
            dist[now_node-1] = nextCost;
            pq.push({nextCost, now_node-1});
        }

        nextCost = time_sum;
        if (now_node*2 <= size && nextCost < dist[now_node*2]) {
            dist[now_node*2] = nextCost;
            pq.push({nextCost, now_node*2});
        }
    }
    cout<<dist[K];
    return 0;
}
