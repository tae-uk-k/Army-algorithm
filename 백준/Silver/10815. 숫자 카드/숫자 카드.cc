#include <iostream>
#include <set>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N,M;
    int card,f_card;
    set<int> deck;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>card;
        deck.insert(card);
    }
    cin>>M;
    for(int j=0;j<M;j++){
        cin>>f_card;
        if(deck.find(f_card)!=deck.end()){
            cout<<1<<' ';
        }
        else{
            cout<<0<<' ';
        }
    }
    return 0;
}