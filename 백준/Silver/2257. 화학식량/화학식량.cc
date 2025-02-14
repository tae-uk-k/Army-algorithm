#include <bits/stdc++.h>
using namespace std;

string s;
stack<int> st;
unordered_map<char, int> w = {{'H', 1}, {'C', 12}, {'O', 16}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    for (char c : s) {
        if (isdigit(c)) {
            int t = st.top(); st.pop();
            st.push(t * (c - '0'));
        } else if (c == '(') {
            st.push(-1);
        } else if (c == ')') {
            int sum = 0;
            while (!st.empty() && st.top() != -1) {
                sum += st.top();
                st.pop();
            }
            st.pop();
            st.push(sum);
        } else {
            st.push(w[c]);
        }
    }
    int res = 0;
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    cout << res;
}
