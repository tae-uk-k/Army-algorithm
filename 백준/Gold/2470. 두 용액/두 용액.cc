#include <bits/stdc++.h>
using namespace std;

const int INF=100001;
int N;


long long solution[INF];
long long int L, R;

int main() {
    cin >> N;
    int left = 0;
	int right = N - 1;
	for (int i = 0; i < N; i++) {
		cin >> solution[i];
	}
    sort(solution, solution + N);
	int ans = abs(solution[left] + solution[right]);
	L = solution[left];
	R = solution[right];
	
	while (left < right) {
	    int tmp = solution[left] + solution[right];
		if (abs(tmp) < ans) {
			ans = abs(tmp);
			L = solution[left];
			R = solution[right];
		}

		if (tmp < 0) {
			left++;
		}
		else {
			right--;
		}
	}
    cout << L << " " << R << "\n";
    return 0;
}