#include<bits/stdc++.h>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int main(){
    int n;
    cin >> n;
    while(n>0){
        int vis[100][100]={0,};
        int arr[100][100]={0,};
        int cnt=0;

        vector<pair<int,int>> V;
        int col,row,k;
        cin >> col >> row>>k;
        while(k>0){
            int c,r;
            cin>>c>>r;
            arr[r][c]=1;
            V.push_back({r,c});
            k--;
        }

        //bfs
        for(auto t:V){
            if(vis[t.first][t.second]==1) continue;
            cnt++;
            queue<pair<int,int>> Q;
            Q.push(t);
            vis[t.first][t.second]=1;
            while(!Q.empty()){
                pair<int,int> cur = Q.front();
                Q.pop();
                for(int i=0;i<4;i++){
                    int x=cur.first+dx[i];
                    int y=cur.second+dy[i];
                    if(x>=row||x<0||y>=col||y<0)continue;
                    if(vis[x][y]==1||arr[x][y]==0)continue;
                    vis[x][y]=1;
                    Q.push({x,y});
                }
                
            }

        }

        cout<<cnt<<'\n';
        
        n--;
    }
    return 0;

}