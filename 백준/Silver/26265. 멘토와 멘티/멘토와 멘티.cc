#include <bits/stdc++.h>
using namespace std;

bool compare(pair<string, string>a, pair<string, string>b){
    if(a.first!=b.first) return a.first < b.first;
    else return a.second > b.second;
}

int main() {
   int N;
   cin>>N;
   vector<pair<string, string>>nameList(N);
   
   for(int i=0; i<N; i++){
       cin>>nameList[i].first>>nameList[i].second;
   }
   
   sort(nameList.begin(), nameList.end(), compare);
   
   for(int i=0; i<N; i++){
       cout<<nameList[i].first<<' '<<nameList[i].second<<"\n";
   }
   
    return 0;
}







