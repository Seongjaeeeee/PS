#include<bits/stdc++.h>
using namespace std;
int note[50][50];
int n,m;//노트의
int stiker[15][15];
int r,c;//스티커의

void rotate(){//현재 r,c스티커를 90도 회전
    int temp[15][15];
     
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            temp[j][r-1-i]=stiker[i][j];
        }
    }
  
    int tmp=r;r=c;c=tmp;//r,c바꾸기
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            stiker[i][j]=temp[i][j];
        }
    }
}

int check(int i,int j){//주어진 시작점에 대해 확인하고 붙이기
    for(int x=0;x<r;x++){
        for(int y=0;y<c;y++){
            if(note[x+i][y+j]==1&&stiker[x][y]==1) return 0;
        }
    }
    //통과했을시
    for(int x=0;x<r;x++){
        for(int y=0;y<c;y++){
            if(stiker[x][y]==1)note[x+i][y+j]=stiker[x][y];
        }
    }
    return 1;
}

void patch(){//스티커를 어디에 붙일지 탐색하고 붙임
    //1.m-c만큼 가로로 이동,n-r만큼 세로로 이동->check
    int num=4;
    while(num>0){
        if(r<=n&&c<=m){
            for(int i=0;i<=n-r;i++){
                for(int j=0;j<=m-c;j++){
                    //i,j는 시작점
                    if(check(i,j)) return;//시작점을 주면 붙일수있는지 판단
                }
            }
        }
        rotate();//2.못찾으면 90도회전 3번
        num--;
    }
    //3.그래도 안되면 cut,찾으면 return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    int k;
    cin>>k;

    for(int i=0;i<k;i++){
        cin>>r>>c;
        for(int x=0;x<r;x++){
            for(int y=0;y<c;y++){
                cin>>stiker[x][y];
            }
        }
        patch();
    }

    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(note[i][j]==1)ans++;
        }
    }
    cout<<ans;
}