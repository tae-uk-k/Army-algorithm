#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<int> inv;
    int N;
    cin >> N;
    
    for (int i = 1; inv.size() < N; i++) {
        string F = to_string(i);
        if (F.find("666") != string::npos) {
            inv.push_back(i);
        }
    }
    
    cout << inv[N - 1];
    return 0;
}
