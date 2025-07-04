#include<bits/stdc++.h>
/*시작점이 여러개인 bfs
->여러 시작점 모두를 큐에 넣자
*/
using namespace std; 
int arr[1000][1000];
int step[1000][1000];//visit의 역할까지 한다 -1이면 방문 안한한것
int main(){
    int dx[4]={0,-1,0,1};
    int dy[4]={1,0,-1,0};
    int row,col;
    cin>>col;
    cin>>row;
    vector<pair<int,int>> boil;//익은 시작점 배열
    for(int i=0;i<row;i++){//입력
        for(int j=0;j<col;j++){
            int x;
            cin >> x;
            arr[i][j]=x;
            if(x==1) boil.push_back({i,j});
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            step[i][j]=-1;
        }
    }
    


    queue<pair<int,int>> Q;//bfs
    for(auto t:boil){
        Q.push({t.first,t.second});
        step[t.first][t.second]=0;
    }
    while(!Q.empty()){
        pair<int,int> cur=Q.front();
        Q.pop();
        for(int j=0;j<4;j++){
            int x=cur.first+dx[j];
            int y=cur.second+dy[j];
            if(x>=row||x<0||y>=col||y<0) continue;
            if(step[x][y]!=-1||arr[x][y]!=0)continue;//이미 접근한거or벽,익은시작점 제외
            Q.push({x,y});
            step[x][y]=step[cur.first][cur.second]+1;
        }
    }

    int mx=-1;
    for(int i=0;i<row;i++){//출력
        for(int j=0;j<col;j++){
            if(step[i][j]==-1&&arr[i][j]==0){//안익은 부분 확인
                cout<<-1;
                return 0;
            }
            if(step[i][j]>mx) mx=step[i][j];
        }
    }
    cout<<mx;

    return 0;
}