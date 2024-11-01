#include <iostream>
using namespace std;

int main() {
	int N;
	long long num[91];
	
	cin >> N;

	num[0] = 0;
	num[1] = 1;
	num[2] = 1;
	for (int i = 3; i <= N; i++) {
		num[i] = num[i - 1] + num[i - 2];
	}

	cout << num[N];

	return 0;
}
