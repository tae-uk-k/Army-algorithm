#include <bits/stdc++.h>
using namespace std;

int N, best = 0;

void moveUp(vector<vector<int>>& A) {
    for (int c = 0; c < N; c++) {
        vector<int> t;
        for (int r = 0; r < N; r++) {
            if (A[r][c]) t.push_back(A[r][c]);
            A[r][c] = 0;
        }
        int idx = 0;
        for (int i = 0; i < t.size(); i++) {
            if (i + 1 < t.size() && t[i] == t[i+1]) {
                A[idx++][c] = t[i] * 2;
                i++;
            } else {
                A[idx++][c] = t[i];
            }
        }
    }
}

void moveDown(vector<vector<int>>& A) {
    for (int c = 0; c < N; c++) {
        vector<int> t;
        for (int r = N - 1; r >= 0; r--) {
            if (A[r][c]) t.push_back(A[r][c]);
            A[r][c] = 0;
        }
        int idx = N - 1;
        for (int i = 0; i < t.size(); i++) {
            if (i + 1 < t.size() && t[i] == t[i+1]) {
                A[idx--][c] = t[i] * 2;
                i++;
            } else {
                A[idx--][c] = t[i];
            }
        }
    }
}

void moveLeft(vector<vector<int>>& A) {
    for (int r = 0; r < N; r++) {
        vector<int> t;
        for (int c = 0; c < N; c++) {
            if (A[r][c]) t.push_back(A[r][c]);
            A[r][c] = 0;
        }
        int idx = 0;
        for (int i = 0; i < t.size(); i++) {
            if (i + 1 < t.size() && t[i] == t[i+1]) {
                A[r][idx++] = t[i] * 2;
                i++;
            } else {
                A[r][idx++] = t[i];
            }
        }
    }
}

void moveRight(vector<vector<int>>& A) {
    for (int r = 0; r < N; r++) {
        vector<int> t;
        for (int c = N - 1; c >= 0; c--) {
            if (A[r][c]) t.push_back(A[r][c]);
            A[r][c] = 0;
        }
        int idx = N - 1;
        for (int i = 0; i < t.size(); i++) {
            if (i + 1 < t.size() && t[i] == t[i+1]) {
                A[r][idx--] = t[i] * 2;
                i++;
            } else {
                A[r][idx--] = t[i];
            }
        }
    }
}

void dfs(int d, vector<vector<int>> A) {
    if (d == 5) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                best = max(best, A[i][j]);
        return;
    }
    for (int k = 0; k < 4; k++) {
        vector<vector<int>> B = A;
        if (k == 0) moveUp(B);
        if (k == 1) moveDown(B);
        if (k == 2) moveLeft(B);
        if (k == 3) moveRight(B);
        dfs(d+1, B);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    dfs(0, board);
    cout << best;
    return 0;
}
