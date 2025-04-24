#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int node, edge, a, b;
		cin >> node>> edge;
		for (int j = 0; j < edge; j++) 
			cin >> a >> b;
		cout << node-1 << '\n';
	}
}