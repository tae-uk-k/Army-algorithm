#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    cin >> input;

    int z = 0, o = 0;

    char last_char = ' '; 
    for (char c : input) {
        if (c != last_char) {
            if (c == '0') {
                z++; 
            } else if (c == '1') {
                o++;
            }
        }
        last_char = c;
    }

    cout << min(z, o); 
    return 0;
}
