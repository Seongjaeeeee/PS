#include<bits/stdc++.h>
using namespace std; 
int main(){
    int arr[500][500]={0,};
    int visit[500][500]={0,};
    int row,col;
    cin>>row;
    cin>>col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            int x;
            cin >> x;
            arr[i][j]=x;
        }
    }
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    int max=0;
    int cnt=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){//bfs시작점
            if(visit[i][j]||arr[i][j]==0) continue;
            queue<pair<int,int>> Q;
            Q.push({i,j});
            visit[i][j]=1;
            cnt++;
            int size=0;
            while(!Q.empty()){
                pair<int,int> rc=Q.front();
                Q.pop();
                size++;
                for(int k=0;k<4;k++){
                    int x=rc.first+dx[k];
                    int y=rc.second+dy[k];
                    if(x>=row||x<0||y>=col||y<0)continue;
                    if(visit[x][y]||arr[x][y]==0)continue;
                    visit[x][y]=1;
                    Q.push({x,y});
                }

            }
            if(size>max) max=size;
        }
    }
    cout<<cnt<<'\n';
    cout<<max;

    return 0;

}