/*해시 맵을 이용해서 가지고있는 숫자카드를 저장한다. 이때 처음나온 카드라면 추가하고 이미 나온카드라면 벨류값을 증가시킨다.
찾아야할 카드를 입력받아서 해시뱁에있는 벨류를 출력한다*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    unordered_map<int, int>card;
    int N,M,Have_card,Fine_card;
    cin>>N;
    
    for(int i=0;i<N;i++){
        cin>>Have_card;
        card[Have_card]++;
    }
    cin>>M;
    for(int j=0;j<M;j++){
        cin>>Fine_card;
        cout<<card[Fine_card]<<' ';
    }
    return 0;
}