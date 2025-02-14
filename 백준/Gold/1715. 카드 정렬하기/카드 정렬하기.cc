#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int ans=0;
    int card;
    priority_queue<int, vector<int>, greater<int>> pq;
	cin >> N;
	if (N == 1) {
		cout << 0 << endl;
		return 0;
	}
	
	for (int i = 0; i < N; i++) {
		cin >> card;
		pq.push(card);
	}
	while (!pq.empty()) {
		int sum = 0;
		sum += pq.top();
		pq.pop();
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
			if (!pq.empty()) pq.push(sum);
		}
		ans += sum;
	}

	cout << ans << endl;
	return 0;
}