#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N,M;
    int sum=0;
    string word;
    cin>>N>>M;
    set<string>S;
    for(int i=0;i<N;i++){
        cin>>word;
        S.insert(word);
    }
    for(int j=0;j<M;j++){
        cin>>word;
        if(S.find(word)!=S.end()){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}