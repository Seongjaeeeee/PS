#include<bits/stdc++.h>
using namespace std;
int arr[500][500];
int vis[500][500];
int temp[500][500];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    
    int times=0;
    while(1){//두개로 나눠지거나 0이 될때까지 무한루프
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j]=0;
                temp[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==1||arr[i][j]==0)continue;
                queue<pair<int,int>> Q;
                cnt++;//bfs돌면서 개수세기
                Q.push({i,j});
                vis[i][j]=1;
                while(!Q.empty()){
                    pair<int,int> cur = Q.front();
                    Q.pop();
                    int sub=0;
                    for(int i=0;i<4;i++){
                        int x=cur.first+dx[i];
                        int y=cur.second+dy[i];
                        if(x>=n||x<0||y>=m||y<0)continue;
                        if(arr[x][y]==0){sub++;continue;}
                        if(vis[x][y]!=0)continue;
                        Q.push({x,y});
                        vis[x][y]=1;
                    }
                    temp[cur.first][cur.second]=arr[cur.first][cur.second]-sub;//나중에 반영
                }
                
            }
        }
        int flag=0;//0확인용
        for(int i=0;i<n;i++){//감소 반영
            for(int j=0;j<m;j++){
                if(temp[i][j]>=0){
                    arr[i][j]=temp[i][j];
                    flag+=temp[i][j];
                }
                else{
                    arr[i][j]=0;
                    flag-=temp[i][j];
                }
            }
        }

        times++;
        if(cnt>=2)break;
        if(flag==0){
            cout<<0;
            return 0;
        }
    }
    cout<<times-1;//bfs를 돌리는건 감소 다음연도이기 때문
    return 0;
}