#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;cin>>N;
    long long cost=0;
    long long len[100000];
    long long node[100000];
    
    for(int i=0; i<N-1; i++){
        cin>>len[i];
    }
    for(int i=0; i<N; i++){
        cin>>node[i];
    }
    
    for(int i=0; i<N; i++){
        int j=i;
        cost+=node[i]*len[j];//일단 다음도시로 가는 기름은 다음도시가 더 싸도 사야함.
        while(1){
            j++;
            if(j>=N-1 || node[i]>=node[j]) break;//다음도시가 더 싸면 굳이 더 사지 말고 다음도시로 이동
            cost+=node[i]*len[j];//다음도시가 더 비싸면 더 싼 도시나올 때 까지 갈 수 있는 기름만 산다.
        }
        i=j-1;//기름을 다 썼을 때 도착하는 도시부터 다시 계산 
    }
    
    cout<<cost;
    return 0;
}