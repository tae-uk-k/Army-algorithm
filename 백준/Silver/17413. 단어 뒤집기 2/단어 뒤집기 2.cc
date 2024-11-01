#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    stack<char> S2;  // 스택 선언
    getline(cin, S);  // 입력 받기

    for (int i = 0; i < S.size(); i++) {
        // 태그의 시작 ('<')을 만났을 때
        if (S[i] == '<') {
            // 스택이 비어있지 않으면 모든 문자를 출력
            while (!S2.empty()) {
                cout << S2.top();
                S2.pop();
            }
            // 태그 내부는 그대로 출력
            while (S[i] != '>') {
                cout << S[i];
                i++;
            }
            cout << S[i];  // '>' 출력
        }
        // 공백을 만났을 때
        else if (S[i] == ' ') {
            // 스택이 비어있지 않으면 모든 문자를 출력
            while (!S2.empty()) {
                cout << S2.top();
                S2.pop();
            }
            cout << ' ';  // 공백 출력
        }
        // 그 외의 문자는 스택에 저장
        else {
            S2.push(S[i]);
        }
    }

    // 남은 스택의 문자 출력
    while (!S2.empty()) {
        cout << S2.top();
        S2.pop();
    }

    return 0;
}
