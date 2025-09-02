#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    
    vector<int> numbers(n);
    map<int, int> freq;
    
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        sum += numbers[i];
        freq[numbers[i]]++;
    }
    
    sort(numbers.begin(), numbers.end());
    
    double avg = (double)sum / n;
    int result_avg = (int)round(avg);
    cout << result_avg << "\n";
    
    int median = numbers[n / 2];
    cout << median << "\n";
    
    int max_freq = 0;
    
    for (auto& p : freq) {
        max_freq = max(max_freq, p.second);
    }
    
    vector<int> modes;
    
    for (auto& p : freq) {
        if (p.second == max_freq) {
            modes.push_back(p.first);
        }
    }
    
    if (modes.size() == 1) {
        cout << modes[0] << "\n";
    } else {
        sort(modes.begin(), modes.end());
        cout << modes[1] << "\n";
    }
    
    int range = numbers[n - 1] - numbers[0];
    cout << range << "\n";
    
    return 0;
}