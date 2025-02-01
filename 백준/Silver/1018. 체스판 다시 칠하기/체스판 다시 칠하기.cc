#include <bits/stdc++.h>
using namespace std;

string comp[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    
    vector<string> board(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    int Min = 100;

    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            int W = 0, B = 0;
            for (int k = 0; k < 8; k++) {
                for (int l = 0; l < 8; l++) {
                    if (board[i + k][j + l] == comp[k][l]) B++;
                    else W++;
                }
            }
            Min = min(Min, min(W, B));
        }
    }

    cout << Min;
    return 0;
}
