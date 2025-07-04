#include<bits/stdc++.h>
using namespace std;
//https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x0D/15683.cpp
//진법을 이용해 더 간단히 풀 수 있음
//방향이 4개이므로 4진법을 이용해 k개의 cctv에 대해 0부터 4^k-1을 4진법으로 적용해(0,1,2)(0,1,3)등의 cctv방향의 모든 경우의 수 구현
//->각각의 cctv에 대해 방향을 정해준다.
/*
// (x,y)에서 dir 방향으로 진행하면서 벽을 만날 때 까지 지나치는 모든 빈칸을 7로 바꿔버림
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 남쪽, 동쪽, 북쪽, 서쪽 순서
void upd(int x, int y, int dir){
  dir %= 4;
  while(1){
    x += dx[dir];
    y += dy[dir];
    if(OOB(x,y) || board2[x][y] == 6) return; // 범위를 벗어났거나 벽을 만나면 함수를 탈출
    if(board2[x][y] != 0) continue; // 해당 칸이 빈칸이 아닐 경우(=cctv가 있을 경우) 넘어감
    board2[x][y] = 7; // 빈칸을 7로 덮음
  }
}
->이 함수를 쓰면 각각의 cctv에 대해 구역을 탐색하는 걸 따로 구현 할 필요가 없음
->cctv종류에 따라 upd함수의 호출 방식만 다르게 하면 됨
ex)else if(board1[x][y] == 4){
        upd(x,y,dir);
        upd(x,y,dir+1);
        upd(x,y,dir+2);
      }
*/

//요약
//1.진법으로 모든 방향의 경우의 수 구현
//2.각각의 (1,2,3,4,5번)cctv가 진법으로 정해진 방향에 따라 탐색하는 걸 구현->upd함수와,cctv별 호출방식을 달리 해 구현
//3.배열을 순회하면서 빈칸은 사각지대이므로 빈칸의 개수 세기





//백트래킹을 이용한 나의 풀이
//cctv의 좌표 기억
//1번은 경우의수가 4,2->2,3->4,4->4,5->1 각각의 case에 따라 감시 구역을 체크하는 방법 구현
//브루트포스로 각각의 cctv가 바라보는 방향을 달리 하면서 전체 탐색->check 배열에 감시 가능한 구역 표시->백트래킹
//cnt로 각각 경우의 check배열 감시구역 세기 
tuple<int,int,int> cctv[10];//각각의 cctv의 좌표 저장 좌표+유형
int arr[10][10];
int check[10][10];//cctv감시 영역 저장=> 1은 감시 한 영역
int n,m;
int cctvnum;//cctv개수
int checkmx=-1;//감시 영역의 최댓값
void re(int origin[][10]){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            check[i][j]=origin[i][j];
        }
    }
}

void func(int k){//k는 인덱스
    if(k==cctvnum){
        int temp=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(check[i][j]==1){
                    temp++;
                }
            }
        }
        if(checkmx<temp)checkmx=temp;
        return;
    }

    int x,y,z;
    tie(x,y,z)=cctv[k];
    int origin[10][10];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            origin[i][j]=check[i][j];
        }
    }//원본 기록

    if(z==1){
        for(int i=y;i<m;i++){//->
            if(arr[x][i]==6)break;
            check[x][i]=1;
        }
        func(k+1);
        re(origin);

        for(int i=y;i>=0;i--){//<-
            if(arr[x][i]==6)break;
            check[x][i]=1;
        }
        func(k+1);
        re(origin);

        for(int i=x;i>=0;i--){//위
            if(arr[i][y]==6)break;
            check[i][y]=1;
        }
        func(k+1);
        re(origin);

        for(int i=x;i<n;i++){//아래
            if(arr[i][y]==6)break;
            check[i][y]=1;
        }
        func(k+1);
        re(origin);
    }


    if(z==2){
        for(int i=y;i<m;i++){//->
            if(arr[x][i]==6)break;
            check[x][i]=1;
        }
        for(int i=y;i>=0;i--){//<-
            if(arr[x][i]==6)break;
            check[x][i]=1;
        }
        func(k+1);
        re(origin);

        for(int i=x;i>=0;i--){//위
            if(arr[i][y]==6)break;
            check[i][y]=1;
        }
        for(int i=x;i<n;i++){//아래
            if(arr[i][y]==6)break;
            check[i][y]=1;
        }
        func(k+1);
        re(origin);
        
    }

    if(z==3){
        for(int i=x;i>=0;i--){//위
            if(arr[i][y]==6)break;
            check[i][y]=1;
        }
        for(int i=y;i<m;i++){//->
            if(arr[x][i]==6)break;
            check[x][i]=1;
        }
        func(k+1);
        re(origin);

        for(int i=x;i>=0;i--){//위
            if(arr[i][y]==6)break;
            check[i][y]=1;
        }
        for(int i=y;i>=0;i--){//<-
            if(arr[x][i]==6)break;
            check[x][i]=1;
        }
        func(k+1);
        re(origin);

        for(int i=x;i<n;i++){//아래
            if(arr[i][y]==6)break;
            check[i][y]=1;
        }
        for(int i=y;i<m;i++){//->
            if(arr[x][i]==6)break;
            check[x][i]=1;
        }
        func(k+1);
        re(origin);

        for(int i=x;i<n;i++){//아래
            if(arr[i][y]==6)break;
            check[i][y]=1;
        }
        for(int i=y;i>=0;i--){//<-
            if(arr[x][i]==6)break;
            check[x][i]=1;
        }
        func(k+1);
        re(origin);
    }

    if(z==4){
        for(int i=x;i>=0;i--){//위
            if(arr[i][y]==6)break;
            check[i][y]=1;
        }
        for(int i=y;i<m;i++){//->
            if(arr[x][i]==6)break;
            check[x][i]=1;
        }
        for(int i=y;i>=0;i--){//<-
            if(arr[x][i]==6)break;
            check[x][i]=1;
        }
        func(k+1);
        re(origin);

        for(int i=x;i<n;i++){//아래
            if(arr[i][y]==6)break;
            check[i][y]=1;
        }
        for(int i=y;i<m;i++){//->
            if(arr[x][i]==6)break;
            check[x][i]=1;
        }
        for(int i=y;i>=0;i--){//<-
            if(arr[x][i]==6)break;
            check[x][i]=1;
        }
        func(k+1);
        re(origin);

        for(int i=x;i>=0;i--){//위
            if(arr[i][y]==6)break;
            check[i][y]=1;
        }
        for(int i=x;i<n;i++){//아래
            if(arr[i][y]==6)break;
            check[i][y]=1;
        }
        for(int i=y;i<m;i++){//->
            if(arr[x][i]==6)break;
            check[x][i]=1;
        }
        func(k+1);
        re(origin);

        for(int i=x;i>=0;i--){//위
            if(arr[i][y]==6)break;
            check[i][y]=1;
        }
        for(int i=x;i<n;i++){//아래
            if(arr[i][y]==6)break;
            check[i][y]=1;
        }
        for(int i=y;i>=0;i--){//<-
            if(arr[x][i]==6)break;
            check[x][i]=1;
        }
        func(k+1);
        re(origin);
        
    }

    if(z==5){
        for(int i=y;i<m;i++){//->
            if(arr[x][i]==6)break;
            check[x][i]=1;
        }
        for(int i=y;i>=0;i--){//<-
            if(arr[x][i]==6)break;
            check[x][i]=1;
        }
        for(int i=x;i>=0;i--){//위
            if(arr[i][y]==6)break;
            check[i][y]=1;
        }
        for(int i=x;i<n;i++){//아래
            if(arr[i][y]==6)break;
            check[i][y]=1;
        }
        func(k+1);
        re(origin);
    }

}

int main(){
    cin>>n>>m;
    int wall=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]>=1&&arr[i][j]<=5){
                cctv[cctvnum]={i,j,arr[i][j]};
                cctvnum++;
            }
            if(arr[i][j]==6){
                wall++;
            }
        }
    }
    
    func(0);
    cout<<n*m-checkmx-wall;
    //cout<<checkmx<<wall;
    return 0;

}
