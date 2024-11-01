#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long N, a, b;
    cin >> N;

    vector<pair<long long, long long>> meetings;

    // 회의 입력 받기
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        meetings.push_back({b, a}); // 끝나는 시간을 먼저 저장
    }

    // 끝나는 시간을 기준으로 정렬 (오름차순)
    sort(meetings.begin(), meetings.end());

    long long end_time = 0;
    int count = 0;

    // 회의 선택
    for (const auto &meeting : meetings) {
        if (meeting.second >= end_time) { // 시작 시간이 현재 끝난 시간 이후면 선택
            end_time = meeting.first; // 끝나는 시간 업데이트
            count++; // 선택한 회의 수 증가
        }
    }

    cout << count;
    return 0;
}
