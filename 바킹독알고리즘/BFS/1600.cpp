#include<bits/stdc++.h>
using namespace std;
//언제가 점프할 최적 시점 인지를 모르므로 말 점프를 한 횟수별로 특정 위치까지의 최단거리를 전부 기록해 두어야함->점프 횟수까지 기록된 걸 전부 큐에 넣어 돌리기
//브루트 포스로 모든 경우의 수 탐색
//말 점프를 하는 경우->다음 층위로 넘어감
//말 점프를 안하는 경우->그 층위 유지

//2206과 유사->큐에 상태까지 넣어야 하며 이렇게 했을때 상태별로 최단거리가 보장된다 + 어느 조건에서 상태가 변화해 다른 층위로 넘어가고,어떤 조건에서 층위가 유지되는지 고려
int arr[202][202];
int step[202][202][32];//마지막은 원숭이가 점프를 한횟수를 나타냄
int dy[12]={1,2,2,1,-1,-2,-2,-1,0,0,-1,1};
int dx[12]={2,1,-1,-2,-2,-1,1,2,1,-1,0,0};

int main(){
    int k,w,h;
    cin>>k>>w>>h;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>arr[i][j];
            for(int t=0;t<=k;t++){
                step[i][j][t]=-1;
            }
        }
    }
    queue<tuple<int,int,int>> Q;
    Q.push({0,0,0});
    step[0][0][0]=0;
    step[0][0][1]=0;

    int anshor=-1;
    while(!Q.empty()){
        int curx,cury,hor;
        tie(curx,cury,hor)=Q.front();
        if(curx==h-1&&cury==w-1){
            anshor=hor;
            break;
        }
        Q.pop();
        for(int i=0;i<12;i++){
            if(hor==k){
                if(i<8) continue;
            }
            int x=curx+dx[i];
            int y=cury+dy[i];
            if(x>=h||x<0||y>=w||y<0||arr[x][y]==1)continue;
            //말일경우
            if(i<8){
                if(step[x][y][hor+1]!=-1)continue;
                Q.push({x,y,hor+1});
                step[x][y][hor+1]=step[curx][cury][hor]+1;
            }
            //말 아닐경우
            else{
                if(step[x][y][hor]!=-1)continue;
                Q.push({x,y,hor});
                step[x][y][hor]=step[curx][cury][hor]+1;
            }
        }

    }
    if(anshor>=0)cout<<step[h-1][w-1][anshor];
    else cout<<-1;
    
}