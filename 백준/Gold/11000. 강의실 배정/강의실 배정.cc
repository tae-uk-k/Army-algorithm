#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>lecture;//강의들의 시작,끝 시간저장하는 우선순위 큐. 시작시간 기준 정렬 수 작은순 
    priority_queue<int, vector<int>, greater<int>> count;
    
    int N;
    cin >>N;
    pair<int, int>a;
    
    for(int i=0; i<N; i++){
        cin>>a.first>>a.second;
        lecture.push(a);
    }
    //처음 강의는 일단 count에 하나 넣어두자. 비교 대상이 필요하니까.
    count.push(lecture.top().second);
    lecture.pop();
    while(!lecture.empty()){
        
        if(lecture.top().first>=count.top()){
            count.pop();
            count.push(lecture.top().second);
            lecture.pop();
        }
        
        else{
            count.push(lecture.top().second);
            lecture.pop();
        }
    }
    cout<<count.size();
    
}