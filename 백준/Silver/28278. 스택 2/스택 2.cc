#include <iostream>
#include <stack>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    
    int T, cmd, p;
    stack<int> num;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> cmd;
        switch (cmd) {
            case 1:
                cin >> p;
                num.push(p);
                break;

            case 2:
                if (!num.empty()) {
                    cout << num.top() << "\n";
                    num.pop();
                } else {
                    cout << -1 << "\n";
                }
                break;

            case 3:
                cout << num.size() << "\n";
                break;

            case 4:
                if (num.empty()) {
                    cout << 1 << "\n";
                } else {
                    cout << 0 << "\n";
                }
                break;

            case 5:
                if (!num.empty()) {
                    cout << num.top() << "\n";
                } else {
                    cout << -1 << "\n";
                }
                break;

            default:
                break;
        }
    }
    return 0;
}
