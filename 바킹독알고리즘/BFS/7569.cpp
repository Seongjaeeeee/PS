#include<bits/stdc++.h>
using namespace std;
int arr[102][102][102];
int step[102][102][102];
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
int main(){
    int col,row,h;
    cin >> col >> row >> h;
    queue<tuple<int,int,int>> Q;
    for(int k=0;k<h;k++){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                step[k][i][j]=-1;//초기화
                int temp;
                cin>>temp;
                arr[k][i][j]=temp;
                if(temp==1){//익은거
                    Q.push({k,i,j});
                    step[k][i][j]=0;
                }
            }
        }
    }

    while(!Q.empty()){
        tuple<int,int,int> cur = Q.front();
        Q.pop();
        for(int i=0;i<6;i++){
            int x = get<1>(cur)+dx[i];
            int y = get<2>(cur)+dy[i];
            int z = get<0>(cur)+dz[i];
            if(x>=row||x<0||y>=col||y<0||z>=h||z<0)continue;
            if(step[z][x][y]!=-1||arr[z][x][y]!=0)continue;//방문한거거나 안익은거 아님 건너뛰기
            step[z][x][y]=step[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
            Q.push({z,x,y});
        }
    }
    int mx=-1;
    for(int k=0;k<h;k++){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(step[k][i][j]==-1&&arr[k][i][j]==0){
                    cout<<-1;
                    return 0;
                }
                if(step[k][i][j]>mx)mx=step[k][i][j];
            }
        }
    }
    cout<<mx;
    return 0;
    
}