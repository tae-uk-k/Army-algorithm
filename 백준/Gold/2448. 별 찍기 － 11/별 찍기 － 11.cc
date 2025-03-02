#include <bits/stdc++.h>
using namespace std;

char a[3072][6144];

void f(int x, int y, int n) {
    if (n == 3) {
        a[x][y] = '*';
        a[x + 1][y - 1] = '*';
        a[x + 2][y - 2] = '*';
        a[x + 2][y - 1] = '*';
        a[x + 2][y] = '*';
        a[x + 2][y + 1] = '*';
        a[x + 2][y + 2] = '*';
        a[x + 1][y + 1] = '*';
    } else {
        f(x, y, n / 2);
        f(x + n / 2, y - n / 2, n / 2);
        f(x + n / 2, y + n / 2, n / 2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    memset(a, ' ', sizeof(a));

    f(0, n - 1, n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
    return 0;
}
