#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    
    vector<pair<string,int>>words;
    unordered_map<string,int>duplication;
    
    string word;
    for(int i=0; i<N; i++){
        cin>>word;
        
        if(word.size()>=M){
            if(duplication.find(word) != duplication.end()){
                duplication.at(word)+=1;
            }
            else{
                duplication[word]=1;
            }
        }
    }
    
    for(const auto& pair : duplication){
        words.push_back(pair);
    }
    
    sort(words.begin(), words.end(), [](pair<string,int> const& l, pair<string, int> const& r)
		{
			if (l.second != r.second)
				return l.second > r.second;

			else if (l.first.length() != r.first.length())
				return l.first.length() > r.first.length();

			else
				return l.first < r.first;
		});
    
    for(const auto& j : words){
        cout<<j.first<<"\n";
    }
    
    return 0;
}























