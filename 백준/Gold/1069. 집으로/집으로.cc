#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y, D, T;
    cin >> X >> Y >> D >> T;
    double L = sqrt((double)X * X + (double)Y * Y);

    double ans1 = L;
    if (T >= D) {
        cout << fixed << setprecision(10) << ans1;
        return 0;
    }

    long long k = (long long)floor(L / D);
    double case2 = k * T + (L - k * D);
    double case3 = (k + 1) * T + ((k + 1) * D - L);

    long long jumps = (long long)ceil(L / D);
    long long count = max(2LL, jumps);
    double case4 = count * T;

    double answer = min({ans1, case2, case3, case4});
    cout << fixed << setprecision(10) << answer;
    return 0;
}
