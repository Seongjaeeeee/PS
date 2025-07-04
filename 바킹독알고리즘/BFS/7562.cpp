#include<bits/stdc++.h>
using namespace std;
int dy[8]={1,2,2,1,-1,-2,-2,-1};
int dx[8]={2,1,-1,-2,-2,-1,1,2};
int main(){
    int n;
    cin>>n;
    while(n>0){
        int step[302][302];
        int l;//크기 l*l
        cin>>l;
        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++){
                step[i][j]=-1;
            }
        }
        int startx,starty,endx,endy;
        cin>>startx>>starty>>endx>>endy;
       
        queue<pair<int,int>> Q;
        Q.push({startx,starty});
        step[startx][starty]=0;
        while(!Q.empty()){
            pair<int,int> cur = Q.front();
            Q.pop();
            for(int i=0;i<8;i++){
                int x= cur.first+dx[i];
                int y= cur.second+dy[i];
                if(x>=l||x<0||y>=l||y<0)continue;
                if(step[x][y]!=-1)continue;
                Q.push({x,y});
                step[x][y]=step[cur.first][cur.second]+1;
            }
        }
        cout<<step[endx][endy]<<'\n';
        n--;
    }
    return 0;
}   