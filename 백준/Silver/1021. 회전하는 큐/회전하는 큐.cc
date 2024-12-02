#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, element;
    cin >> N >> M;
    deque<int> q;

    // 1부터 N까지 큐에 넣기
    for (int i = 1; i <= N; ++i) {
        q.push_back(i);
    }

    int count = 0;
    while (M--) {
        cin >> element;

        // 큐에서 element의 위치 찾기
        auto it = find(q.begin(), q.end(), element);
        int idx = distance(q.begin(), it);

        // 회전할 최소 횟수 구하기
        if (idx <= q.size() / 2) {
            // 왼쪽 회전
            while (q.front() != element) {
                q.push_back(q.front());
                q.pop_front();
                count++;
            }
        } else {
            // 오른쪽 회전
            while (q.front() != element) {
                q.push_front(q.back());
                q.pop_back();
                count++;
            }
        }

        // element를 큐에서 제거
        q.pop_front();
    }

    cout << count << endl;
    return 0;
}
