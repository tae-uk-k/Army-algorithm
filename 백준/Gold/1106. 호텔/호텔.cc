#include <bits/stdc++.h>
using namespace std;
int INF=987654321;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,necessaryCustomer;
    cin>>necessaryCustomer>>N;
    vector<pair<int,int>> city;
    vector<int> Minimum_price_per_customer(necessaryCustomer+101, INF);//여기에는 고객 수 별로 드는 가격이 저장된다.
    Minimum_price_per_customer[0]=0;
    
    for(int i=0; i<N; i++){
        int a,b;
        cin>>a>>b;//비용과 그 비용으로 얻을 수 있는 고객의 수
        city.push_back({a,b});
    }

    for(int i=1; i<=necessaryCustomer+100; i++){//여기서 C는 고객 수 이다.
        for(auto[c, v] : city){//여기서 c는 가격, v는 고객 수 이다.
            if((i-v)<0 || Minimum_price_per_customer[i-v]==INF)continue;
            Minimum_price_per_customer[i]=min(Minimum_price_per_customer[i],(Minimum_price_per_customer[i-v]+c));
        }
    }

    int answer = INF;
    for(int i=necessaryCustomer; i<necessaryCustomer+100; i++){
        answer = min(answer, Minimum_price_per_customer[i]);
    }
    cout << answer;
    return 0;
} 