#include<bits/stdc++.h>
using namespace std;

/*
//별해 n^2
섬 분류: BFS로 탐색하며 1인 칸들을 각각의 섬 번호로 변경.섬 1은 1,섬 2는 2,섬 3은 3등.....
다리 건설: 모든 섬의 요소를 전부 큐에 넣고 BFS로 확장하며 <숫자가 다른 섬>을 만날 때의 최소 거리를 계산.
다리의 최소 길이: ans 변수에 저장된 값이 최소 다리 길이.
*/

//고민 한 점->섬에 구멍이 있어도 최단거리로 도달 못하기 때문에 걍 무시해도 됨
int arr[102][102];
int vis[102][102];
int step[102][102];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int main(){
    int ans=100000000;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int cnt=0;
    queue<pair<int,int>> Q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]==1)continue;
            if(arr[i][j]==0)continue;
            queue<pair<int,int>> bQ;//한 섬 마다 큐를 파기->최단거리
            for(int a=0;a<n;a++){
                for(int b=0;b<n;b++){
                    step[a][b]=-1;
                }
            }
            Q.push({i,j});
            vis[i][j]=1;
            while(!Q.empty()){
                pair<int,int> cur=Q.front();
                step[cur.first][cur.second]=0;//전부 방문 처리 해주기->이 섬을 0으로 처리해줘서 딴 섬과 구분
                Q.pop();
                int edge=0;
                for(int t=0;t<4;t++){
                    int x=cur.first+dx[t];
                    int y=cur.second+dy[t];
                    if(x>=n||x<0||y>=n||y<0)continue;
                    if(vis[x][y]==1)continue;
                        if(arr[x][y]==0){//주위에 0이 있으면 가장자리
                            edge=1;
                            continue;
                        }
                    Q.push({x,y});
                    vis[x][y]=1;
                }
                if(edge==1){//가장자리들 전부 큐에 넣기
                    bQ.push({cur.first,cur.second});
                }
            
            }
            int endflag=0;
            while(!bQ.empty()){
                pair<int,int> cur=bQ.front();
                bQ.pop();
                for(int t=0;t<4;t++){
                    int x=cur.first+dx[t];
                    int y=cur.second+dy[t];
                    if(x>=n||x<0||y>=n||y<0)continue;
                    if(step[x][y]!=-1)continue;
                    if(arr[x][y]==1){//가장 먼저 만나는 1이 최단거리
                        if(ans>step[cur.first][cur.second]){
                            ans=step[cur.first][cur.second];
                        }
                        endflag=1;
                        break;
                    }
                    bQ.push({x,y});
                    step[x][y]=step[cur.first][cur.second]+1;
                }
                if(endflag==1)break;
            }
        }
    }
    cout<<ans;
    
}