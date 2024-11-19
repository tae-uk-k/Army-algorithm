#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin>>N;
    for(int i=0; i<N; i++){//N만큰 반복하며 테스트 케이스 모두 수행
        int quantity;//문서의 수
        int q_doc_sequence;//찾을 문서가 문서중에 현재 위치한 순서
        int print_count=0;//프린트가 이루어진 횟수
        cin>>quantity>>q_doc_sequence;
        
        priority_queue<int>heep_doc;//중요도가 높은 프린트 순으로 정렬
        queue<int>print_doc;//인쇄물이 주문받은 순서
        
        for(int j=0; j<quantity; j++){
            int print;//각 인쇄물의 중요도
            cin>>print;
            heep_doc.push(print);//각각 저장
            print_doc.push(print);
        }
        
        while(true){//여기서 우선 두가지 경우로 나눈다. => 프린트 되거나 뒤로 가거나. 
            if(heep_doc.top()==print_doc.front()){//각각 pop하고 프린트 수+1;
                heep_doc.pop();
                print_doc.pop();
                print_count++;
                if(q_doc_sequence==0){//찾는 인쇄물이 출력됐으면 순서 출력하고 다음 테스트 케이스로
                    cout<<print_count<<"\n";
                    break;
                }
                else{//다른 인쇄물이 출력 됐으면 앞 자리가 하나 줄었으므로 -1
                    q_doc_sequence--;
                }
            }
            else{//뒤로 간다면 뒤로가는게 알아낼 문서인지 다른 문서인지 확인
                print_doc.push(print_doc.front());
                print_doc.pop();
                if(q_doc_sequence==0){
                    q_doc_sequence=print_doc.size()-1;//찾을 인쇄물이 맨뒤로 간거라면 맨뒤의 번호로 바꿔줌
                }
                else{//아니면 앞으로 한칸 땡기고
                    q_doc_sequence--;
                }
            }
        }
    }
    return 0;
}