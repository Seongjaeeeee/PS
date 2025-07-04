#include<bits/stdc++.h>
//분기가 있으니깐 조합으로 모든 경우의 수->인접 확인(bfs)이용->s개수 확인->출력
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int answer;

int main(){
    string arr[5];
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }//입력

    int per[25]={0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    do{
        vector<pair<int,int>> ans;//뽑힌 조합 넣는 배열
        for(int i=0;i<25;i++){
            if(per[i]==0) ans.push_back({i/5,i%5});
        }
        //인접확인
        queue<pair<int,int>> Q;
        int isused[5][5]={0,};
        Q.push(ans[0]);
        isused[ans[0].first][ans[0].second]=1;
        int cnt=0;
        while(!Q.empty()){
            int adjflag=0;
            pair<int,int> cur=Q.front();
            Q.pop();
            for(int j=0;j<4;j++){
                int x=cur.first+dx[j];
                int y=cur.second+dy[j];
                if(x<0||x>=5||y<0||y>=5)continue;
                if(isused[x][y])continue;
                for(int k=0;k<7;k++){//찾으면 넣기
                    if(x==ans[k].first&&y==ans[k].second){
                        cnt++;
                        Q.push(ans[k]);
                        isused[x][y]=1;
                    }
                }
            }
        }
            
        if(cnt==6){//인접할경우 s개수세기
            int num=0;
            for(int i=0;i<7;i++){
                if(arr[ans[i].first][ans[i].second]=='S'){
                    num++;
                }
            }
            if(num>=4)answer++;
        }

    }
    while(next_permutation(per,per+25));
    
    cout<<answer;
    return 0;
}