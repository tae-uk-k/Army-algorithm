#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N, M, start, goal;
    cin >> N >> M;

    vector<int> dist(N + 1, INF);
    vector<vector<pair<int,int>>> bus(N + 1);

    for (int i = 0; i < M; i++) {
        int now_city, goal_city, cost;
        cin >> now_city >> goal_city >> cost;
        bus[now_city].push_back({goal_city, cost});
    }

    cin >> start >> goal;
    dist[start] = 0;

    priority_queue< pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>> > pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [cost, now] = pq.top();
        pq.pop();

        if (dist[now] < cost) continue;

        for (auto [next, weight] : bus[now]) {
            int nextCost = cost + weight;
            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }

    cout << dist[goal];
    return 0;
}
