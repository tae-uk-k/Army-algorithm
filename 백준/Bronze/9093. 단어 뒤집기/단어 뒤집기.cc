#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();

    for (int i = 0; i < T; i++) {
        string line;
        getline(cin, line);
        
        stringstream ss(line);
        string word;

        while (ss >> word) { 
            for (int j = word.size() - 1; j >= 0; j--) {
                cout << word[j];
            }
            cout << ' ';
        }
        cout << "\n";
    }
    
    return 0;
}
