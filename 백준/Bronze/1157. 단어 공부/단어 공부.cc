#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    string word;
    cin >> word;
    map<char, int> score;

    for (int i = 0; i < word.size(); i++) {
        word[i] = toupper(word[i]);
        score[word[i]]++;
    }

    char maxKey = '?';
    int maxValue = 0;

    for (const auto& pair : score) {
        if (pair.second > maxValue) {
            maxValue = pair.second;
            maxKey = pair.first;
        } else if (pair.second == maxValue) {
            maxKey = '?';
        }
    }

    cout << maxKey;
    return 0;
}
