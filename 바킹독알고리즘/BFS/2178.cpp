#include<bits/stdc++.h>
using namespace std;

int arr[102][102];
int vis[102][102];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int step[102][102];
 
int main(){
    int row,column;
    cin>>row>>column;
    for(int i=0;i<row;i++){//일케 안하고 string배열에 받아도 됨됨
        string temp;
        cin>>temp;
        for(int j=0;j<column;j++){
            if(temp[j]=='1')arr[i][j]=1;
            else arr[i][j]=0;
        }
    }   

    queue<pair<int,int>> Q;
    Q.push({0,0});
    vis[0][0] = 1;
    step[0][0] = 0;//-1로 초기화 해 놓으면 vis역할까지 가능
    while(!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int x=cur.first+dx[i];
            int y=cur.second+dy[i];
            if(x>=row||x<0||y>=column||y<0) continue;
            if(vis[x][y]==1||arr[x][y]==0)continue;
            Q.push({x,y});
            vis[x][y]=1;
            step[x][y]=step[cur.first][cur.second]+1;
        }
    }
   cout << step[row-1][column-1]+1;
}