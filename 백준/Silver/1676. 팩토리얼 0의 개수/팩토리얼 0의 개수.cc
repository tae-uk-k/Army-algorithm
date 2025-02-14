#include<bits/stdc++.h>
using namespace std;

int main(){
	int sum = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		if (i % 5 == 0)	{
			sum++;
			if (i % 25 == 0)sum++;
			if (i % 125 == 0)sum++;
		}
	}
    cout << sum;
}