#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin>>N;
    string s;
    unordered_map<string, int>book;
    vector<pair<string, int>>sorted_book;
    
    for(int i=0; i<N; i++){
        cin>>s;
        book[s]+=1;
    }
    
    for(auto k : book){
        sorted_book.push_back(k);
    }
    
    sort(sorted_book.begin(), sorted_book.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second == b.second)
            return a.first < b.first; // second가 같으면 first를 기준으로 정렬
        return a.second > b.second; // second를 기준으로 정렬
    });
    
    cout<<sorted_book[0].first;
    return 0;
}