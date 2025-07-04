#include<bits/stdc++.h>
using namespace std;
//1.M개를 고른다->m개보다 더 폐업시켰을 경우 치킨 거리는 무조건 증가아님 유지->폐업시키지 않을 M개 구하기
//2.M개를 고르는 모든 경우의 수 구현->next_permutation
//3.각각의 경우의 수에 대해 bfs를 이용해 치킨거리 구하기->!!!!!!!bfs보다 걍 직접 집 별로 M개의 치킨집과의 거리를 계산하는게 빠름!!!!!!!!!!!!!
int n,m;
int arr[52][52];
vector<pair<int,int>> chicken;//치킨집 목록
vector<pair<int,int>> house;
int idx[15];//이 배열에서 값이 1인 애들만 남기기
int ans=100000000;//치킨 거리의 최솟값 저장

void chicken_dist(){//각각의 집에 대해 최소거리를 구하고 합하기(뽑힌 치킨집에 대해서만)
    int chicknum=0;//이 case의 치킨거리
    for(int i=0;i<house.size();i++){
        int mn=100000000;//각각의 집에 대한 최소거리 저장
        for(int j=0;j<chicken.size();j++){
            if(idx[j]!=1)continue;//안뽑힌건 skip
            int temp=abs(chicken[j].first-house[i].first)+abs(chicken[j].second-house[i].second);
            if(temp<mn)mn=temp;
        }
        chicknum+=mn;
    }
    if(ans>chicknum)ans=chicknum;

}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j]==2){
                chicken.push_back({i,j});
            }
            if(arr[i][j]==1){
                house.push_back({i,j});
            }
        }
    }
    vector<int> V;
    for(int i=0;i<chicken.size();i++){
        if(i<m)V.push_back(0);//m개 뽑기위해 m개의 0 대입
        else V.push_back(1);
    }
    do{
        for(int i=0;i<V.size();i++){
            idx[i]=0;
            if(V[i]==0){
                idx[i]=1;
            }
        }
        chicken_dist();
    }
    while(next_permutation(V.begin(),V.end()));//모든 경우의 수 
    cout<<ans;
}