#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int N; cin >> N;
	vector<string> list;
	for (int i = 0; i < N; i++) {
		string tmp; cin >> tmp;
		list.push_back(tmp);
	}
	sort(list.begin(), list.end());
	int count = 1;
	for (int i = 0; i < N-1; i++) {
		if (list[i].size() <= list[i + 1].size()) {
			string str = list[i + 1].substr(0,list[i].size());
			if (!list[i].compare(str)) {
				continue;
			}
		}
		count++;
	}
	cout << count << endl;
	return 0;
}