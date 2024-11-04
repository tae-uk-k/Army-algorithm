#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, X;
    cin >> N;

    deque<int> dq;
    string Cd;

    for (int i = 0; i < N; i++) {
        cin >> Cd;
        
        if (Cd == "push_front") {
            cin >> X;
            dq.push_front(X);
        } 
        else if (Cd == "push_back") {
            cin >> X;
            dq.push_back(X);
        } 
        else if (Cd == "pop_front") {
            if (!dq.empty()) {
                cout << dq.front() << "\n";
                dq.pop_front();
            } 
            else {
                cout << -1 << "\n";
            }
        } 
        else if (Cd == "pop_back") {
            if (!dq.empty()) {
                cout << dq.back() << "\n";
                dq.pop_back();
            } 
            else {
                cout << -1 << "\n";
            }
        } 
        else if (Cd == "size") {
            cout << dq.size() << "\n";
        } 
        else if (Cd == "empty") {
            if (!dq.empty()) {
                cout << 0 << "\n";
            } 
            else {
                cout << 1 << "\n";
            }
        } 
        else if (Cd == "front") {
            if (!dq.empty()) {
                cout << dq.front() << "\n";
            } 
            else {
                cout << -1 << "\n";
            }
        } 
        else if (Cd == "back") {
            if (!dq.empty()) {
                cout << dq.back() << "\n";
            } 
            else {
                cout << -1 << "\n";
            }
        }
    }

    return 0;
}
