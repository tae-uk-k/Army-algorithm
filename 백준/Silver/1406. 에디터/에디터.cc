#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    

    list<char> charList(S.begin(), S.end());
    

    auto cursor = charList.end();

    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        char a, b;
        cin >> a;
        
        if (a == 'L') {
          
            if (cursor != charList.begin()) {
                cursor--;
            }
        } 
        else if (a == 'D') {

            if (cursor != charList.end()) {
                cursor++;
            }
        } 
        else if (a == 'B') {
          
            if (cursor != charList.begin()) {
                auto temp = cursor;
                --temp;
                charList.erase(temp);
            }
        } 
        else if (a == 'P') {
   
            cin >> b;
            charList.insert(cursor, b);
        }
    }


    for (char c : charList) {
        cout << c;
    }
    cout << endl;

    return 0;
}
