#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end()); 
    
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int target;
        cin >> target;
        
        
        int left = 0, right = n - 1;
        bool found = false;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) {
                found = true;
                break;
            }
            else if (arr[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        if (found)
            cout << "1\n";
        else
            cout << "0\n";
    }
    
    return 0;
}
