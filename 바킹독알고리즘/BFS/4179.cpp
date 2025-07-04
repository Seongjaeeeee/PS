#include<bits/stdc++.h>
//시작점이두 종류인 bfs이므로 각각에 대해 따로 BFS를 돌리고 추후에 비교
//->서로 독립적이므로사용 가능한방법 불이 전파될때 J한테 영향을 받지 않기에
//서로 영향을 준다면 시간순으로 A,B를 동시에 진행시켜야함!
using namespace std;
string arr[1002];//기본 배열
int stepJ[1002][1002];
int stepFire[1002][1002];
int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};
int main(){
    int row,col;
    cin >> row >> col;
    pair<int,int> J;
    vector<pair<int,int>> F;
    for(int i=0;i<row;i++){
        string temp;
        cin>>temp;
        arr[i]=temp;
        for(int j=0;j<col;j++){
            if(temp[j]=='J')J={i,j};
            if(temp[j]=='F')F.push_back({i,j});
        }
    }//입력
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            stepFire[i][j]=-1;
            stepJ[i][j]=-1;
        }
    }//초기화

    queue<pair<int,int>> Q;
    for(auto x: F){
        Q.push(x);
        stepFire[x.first][x.second]=0;
    }
    while(!Q.empty()){//불f가 각칸에 접근하는 시간 저장장
        pair<int,int> cur=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int x=cur.first+dx[i];
            int y=cur.second+dy[i];
            if(x>=row||x<0||y>=col||y<0)continue;
            if(stepFire[x][y]!=-1||arr[x][y]=='#')continue;
            Q.push({x,y});
            stepFire[x][y]=stepFire[cur.first][cur.second]+1;
        }
    }
    
    queue<pair<int,int>> Qj;
    Qj.push({J.first,J.second});
    stepJ[J.first][J.second]=0;
    while(!Qj.empty()){
        pair<int,int> cur=Qj.front();
        Qj.pop();
        for(int i=0;i<4;i++){
            int x=cur.first+dx[i];
            int y=cur.second+dy[i];
            if(x>=row||x<0||y>=col||y<0)continue;//여기서 바로 답 나오게 하는게 더 간단.
            if(stepJ[x][y]!=-1||arr[x][y]=='#')continue;
            if(stepFire[x][y]!=-1&&(stepFire[x][y]<=stepJ[cur.first][cur.second]+1))continue;
            //여기서 stepFire[x][y]!=-1 필수,불은 접근 못하고 J는할수 있는게 있기에 불이 젙파된 곳에 대해서만 판단해야함
            Qj.push({x,y});
            stepJ[x][y]=stepJ[cur.first][cur.second]+1;
        }
    }

    int min=100000000;
    for(int i=0;i<row;i++){
        if(stepJ[i][0]!=-1&&stepJ[i][0]<min)min=stepJ[i][0];
        if(stepJ[i][col-1]!=-1&&stepJ[i][col-1]<min)min=stepJ[i][col-1];
    }
    for(int j=0;j<col;j++){
        if(stepJ[0][j]!=-1&&stepJ[0][j]<min)min=stepJ[0][j];
        if(stepJ[row-1][j]!=-1&&stepJ[row-1][j]<min)min=stepJ[row-1][j];
    }
    if(min==100000000) cout<<"IMPOSSIBLE";
    else cout<<min+1;
    
    return 0;
}