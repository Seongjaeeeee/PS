#include<bits/stdc++.h>
using namespace std;
string arr[1002];
int step[1000][1000];
int stepf[1000][1000];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int main(){
    int n;
    cin>>n;
    while(n>0){
        int col,row;
        cin>>col>>row;
        for(int i=0;i<row;i++){
            string temp;
            cin>> temp;
            arr[i]=temp;
        }//배열입력
        queue<pair<int,int>> Q;
        queue<pair<int,int>> Qf;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                stepf[i][j]=-1;
                step[i][j]=-1;
                if(arr[i][j]=='@'){
                    Q.push({i,j});
                    step[i][j]=0;
                }
                if(arr[i][j]=='*'){
                    Qf.push({i,j});
                    stepf[i][j]=0;
                }
            }
        }

        while(!Qf.empty()){
            pair<int,int> cur=Qf.front();
            Qf.pop();
            for(int i=0;i<4;i++){
                int x=cur.first+dx[i];
                int y=cur.second+dy[i];
                if(x>=row||x<0||y>=col||y<0)continue;
                if(stepf[x][y]!=-1||arr[x][y]=='#')continue;
                Qf.push({x,y});
                stepf[x][y]=stepf[cur.first][cur.second]+1;
            }
        }//불

        int escape=0;
        while(!Q.empty()){
            pair<int,int> cur=Q.front();
            Q.pop();
            for(int i=0;i<4;i++){
                int x=cur.first+dx[i];
                int y=cur.second+dy[i];
                if(x>=row||x<0||y>=col||y<0){
                    cout<<step[cur.first][cur.second]+1<<'\n';
                    escape=1;
                    break;
                }
                if(step[x][y]!=-1||arr[x][y]=='#')continue;
                if(stepf[x][y]!=-1&&step[cur.first][cur.second]+1>=stepf[x][y])continue;
                Q.push({x,y});
                step[x][y]=step[cur.first][cur.second]+1;
            }
            if(escape==1)break;
        }//상준


        if(escape==0)cout<<"IMPOSSIBLE"<<'\n';

        n--;
    }
    return 0;
}