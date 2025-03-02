#include <bits/stdc++.h>
using namespace std;

vector<set<int>>possible;
int N;

void dfs(vector<int>& num, int start){
    set<int>s;
    s.insert(start);
    vector<int>visited(N+1, -1);
    int cur=start;
    int next=num[start];
    while(true){
        if(visited[num[next]]==0)break;
        if(visited[num[next]]==-1){
            cur=next;
            next=num[next];
            visited[num[cur]]=0;
        }
        if(cur==start){
            possible.push_back(s);
            break;
        }
    }
}

int main() {
    
    int sum=0;
    priority_queue<int, vector<int>, greater<int>> q;
    cin>>N;
    
    vector<int>num(N+1, -1);
    for(int i=1; i<=N; i++){
        cin>>num[i];
    }
    for(int i=1; i<=N; i++){
        dfs(num, i);
    }
    for(int i=0; i<possible.size(); i++){
        sum+=possible[i].size();
        for (set<int>::iterator iter = possible[i].begin(); iter != possible[i].end(); iter++) {
	        q.push(*iter);
        }
    }
    cout<<sum<<"\n";
    while(!q.empty()){
        cout<<q.top()<<"\n";
        q.pop();
    }
    
    return 0;
}