#include<bits/stdc++.h>
using namespace std;
//가중치 다르니깐 먼저 접근한다고 최단거리가 아닐수도?->다시 방문해서 업데이트 할 경우도 고려->다익스트라와 유사
int step[100002];
int main(){
    int n,k;//수빈,동생
    cin>>n>>k;
    for(int i=0;i<=100000;i++){
        step[i]=-1;
    }

    queue<int> Q;
    Q.push(n);
    step[n]=0;
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        int a=cur*2;
        if(a<=100000&&a>=0){
            if(step[a]==-1){
                Q.push(a);
                step[a]=step[cur];
            }
            else if(step[a]>step[cur]){
                Q.push(a);
                step[a]=step[cur];
            }
        }
        a=cur+1;
        if(a<=100000&&a>=0){
            if(step[a]==-1){
                Q.push(a);
                step[a]=step[cur]+1;
            }
            else if(step[a]>step[cur]+1){
                Q.push(a);
                step[a]=step[cur]+1;
            }
        }
        a=cur-1;
        if(a<=100000&&a>=0){
            if(step[a]==-1){
                Q.push(a);
                step[a]=step[cur]+1;
            }
            else if(step[a]>step[cur]+1){
                Q.push(a);
                step[a]=step[cur]+1;
            }
        }
    }
    cout<<step[k];
    return 0;
}
//별해 0-1bfs->가중치가 0과 1일 경우에 최단거리를 찾는 bfs
/*
#include <bits/stdc++.h>
using namespace std;

int n,k;
int dist[200002];
int main(void) {
  cin >> n >> k;
  int MX = 200000;
  fill(dist,dist+MX,-1);

  deque<int> dq;
  dq.push_back(n);
  dist[n]=0;
  while(!dq.empty()){
    int cur = dq.front(); dq.pop_front();->꺼내는건 앞에서
    if( 2*cur < MX && dist[2*cur] == -1){
      dist[2*cur] = dist[cur];
      dq.push_front(2*cur);->우선순위가 앞인 0은 앞쪽에 넣어서 먼저 처리하도록
    }
    for(int nxt : {cur-1,cur+1}){
      if(nxt < 0 or nxt >= MX or dist[nxt] != -1) continue;
      dist[nxt] = dist[cur]+1;
      dq.push_back(nxt);->우선순위가 뒤인 1은 뒤쪽에 넣어서 나중에 처리하도록 
    }
  } 
  cout << dist[k];
}
*/