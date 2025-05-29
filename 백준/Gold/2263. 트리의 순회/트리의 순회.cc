#include <bits/stdc++.h>
using namespace std;

vector<int> inord, postord;
int idx[100001];
int N;

void get_pre(int in_s, int in_e, int post_s, int post_e) {
    if (in_s > in_e || post_s > post_e) return;
    int root = postord[post_e];
    cout << root << ' ';
    int root_idx = idx[root];
    int left_size = root_idx - in_s;
    get_pre(in_s, root_idx - 1, post_s, post_s + left_size - 1);
    get_pre(root_idx + 1, in_e, post_s + left_size, post_e - 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    inord.resize(N + 1);
    postord.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> inord[i];
        idx[inord[i]] = i;
    }
    for (int i = 1; i <= N; i++) {
        cin >> postord[i];
    }

    get_pre(1, N, 1, N);
    return 0;
}
