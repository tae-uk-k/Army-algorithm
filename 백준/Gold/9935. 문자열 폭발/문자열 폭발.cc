#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string text;
    string C4;
    cin>>text>>C4;
    char Cstart=C4[0];
    deque<char>S1;
    deque<char>S2;
    
    for(char c: text){
        S1.push_back(c);//일단 S1에다가 다 넣어두고
    }
    
    while(!S1.empty()){
        S2.push_back(S1.front());
        S1.pop_front();
        if(S2.back()==Cstart){//폭탄의 앞글자 발견하면 탐색시작
            for(int i=0; i<C4.size(); i++){
                if(C4[i]!=S2.back()){
                    S1.push_front(S2.back());
                    S2.pop_back();
                    break;
                }//탐색하다가 안 맞으면 빠져나오기
                
                if(i==C4.size()-1){//마지막까지 탐색했는데 폭탄이 맞으면,
                
                    while(S2.back()!=Cstart){//S2의 맨 뒤가 폭탄의 앞글자일 때 까지 다 삭제
                        S2.pop_back();
                    }
                    
                    S2.pop_back();//폭탄 앞글자 까지 다 삭제.
                    
                    //폭탄 길이-1만큼 롤백
                    for(int j=0; j<i; j++){
                        if(S2.empty())break;
                        S1.push_front(S2.back());
                        S2.pop_back();
                    }
                    break;
                }
                if(S1.empty())break;
                S2.push_back(S1.front());
                S1.pop_front();
            }
        }
    }
    if(S2.empty()){
        cout<<"FRULA";
        return 0;
    }
    string S;
    while(!S2.empty()){
        S+=S2.front();
        S2.pop_front();
    }
    cout<<S;
    return 0;
}












