#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, int> num;
int A, B;

void bfs() {
    queue<long long> q;
    q.push(A);
    num[A] = 0;

    while (!q.empty()) {
        long long cur = q.front();
        q.pop();
        long long next1 = cur * 2;
        long long next2 = cur * 10 + 1;

        if (next1 < B+1 && (num[next1] == 0 || num[next1] > num[cur] + 1)) {
            num[next1] = num[cur] + 1;
            q.push(next1);
        }

        if (next2 < B+1 && (num[next2] == 0 || num[next2] > num[cur] + 1)) {
            num[next2] = num[cur] + 1;
            q.push(next2);
        }
    }
}

int main() {
    cin >> A >> B;
    bfs();
    cout << (num[B] == 0 ? -1 : num[B] + 1);
    return 0;
}
