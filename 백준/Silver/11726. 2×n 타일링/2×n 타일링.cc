#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<long long> tile;
    int N;
    cin >> N;

    tile.push_back(1);
    tile.push_back(1);

    for (int i = 2; i <= N; i++) {
        tile.push_back((tile[i-1] + tile[i-2]) % 10007);
    }
    
    cout << tile[N];
    
    return 0;
}
