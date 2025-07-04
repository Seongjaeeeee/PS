#include<bits/stdc++.h>
using namespace std;
string arr[102];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int cnt=0;//적록색약이 아닌경우
int weekcnt=0;
void bfs1(int n,char target){
    int vis[102][102]={0,};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=target)continue;
            if(vis[i][j]==1)continue;
            cnt++;
            queue<pair<int,int>> Q;
            Q.push({i,j});
            vis[i][j]==1;
            while(!Q.empty()){
                pair<int,int> cur = Q.front();
                Q.pop();
                for(int k=0;k<4;k++){
                    int x=cur.first+dx[k];
                    int y=cur.second+dy[k];
                    if(x<0||x>=n||y<0||y>=n)continue;
                    if(vis[x][y]==1||arr[x][y]!=target)continue;
                    Q.push({x,y});
                    vis[x][y]=1;
                }
            }

        }
    }
}
void bfs2(int n){
    int vis[102][102]={0,};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]=='B')continue;
            if(vis[i][j]==1)continue;
            weekcnt++;
            queue<pair<int,int>> Q;
            Q.push({i,j});
            vis[i][j]==1;
            while(!Q.empty()){
                pair<int,int> cur = Q.front();
                Q.pop();
                for(int k=0;k<4;k++){
                    int x=cur.first+dx[k];
                    int y=cur.second+dy[k];
                    if(x<0||x>=n||y<0||y>=n)continue;
                    if(vis[x][y]==1||arr[x][y]=='B')continue;
                    Q.push({x,y});
                    vis[x][y]=1;
                }
            }

        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        arr[i]=temp;
    }
    bfs1(n,'B');
    weekcnt=cnt;
    bfs1(n,'G');
    bfs1(n,'R');
    bfs2(n);
    
    cout<<cnt<<' '<<weekcnt;
    return 0;
}