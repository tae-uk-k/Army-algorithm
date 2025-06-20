#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int,int>> jobs(N);
    for (int i = 0; i < N; i++) {
        cin >> jobs[i].first >> jobs[i].second;
    }


    sort(jobs.begin(), jobs.end(),
         [](auto &a, auto &b){
             return a.first < b.first;
         });


    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto &job : jobs) {
        int t = job.first;
        int r = job.second;
        pq.push(r);
        if ((int)pq.size() > t) {
            pq.pop();
        }
    }

    long long sum = 0;
    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    cout << sum;

    return 0;
}
