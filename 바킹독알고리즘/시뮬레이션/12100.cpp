#include<bits/stdc++.h>
using namespace std;
/*
현재 코드는 4방향에 대해 미는것을 전부 구현을 했지만 
한 방향으로 미는것만 구현하고 전체 보드자체를 원하는 방향으로 회전시키면 더 효율적으로 구현가능 
*/
int board[25][25];
int temp[25][25];//얘를 실제 조작
int n;
stack<pair<int,int>> S;//<값,합쳐졌는지 여부>
void drag(int a,int b){//주어진 좌표의 값을 스택에 넣는다(하나의 원소를 밀고 합치는 연산의 역할)
    if(S.empty()) S.push({temp[a][b],0});
    else if(S.top().second==1) S.push({temp[a][b],0});//이미 합쳐진 것이 top
    else if(S.top().first==temp[a][b]){
        S.pop();
        S.push({temp[a][b]+temp[a][b],1});//같으면 두배
    }
    else S.push({temp[a][b],0});//다르면 넣어주기
    temp[a][b]=0;
}

void mov(int dir){//정해진 방향으로 미는 함수
    if(dir==0){//상
        for(int i=0;i<n;i++){//i번째 열을 처리
            for(int j=0;j<n;j++){//j가 하나의 열을 순회,미는 방향에 가까운것부터 넣어줘야됨
                if(temp[j][i]!=0){//0아닌 것 만 밀면 됨
                    drag(j,i);
                }
            }
            while(!S.empty()){//스택에 남은건 밀고 합쳐진 숫자들->그대로 꺼내주면 됨
                temp[S.size()-1][i]=S.top().first;
                S.pop();
            }
        }
    }

    if(dir==3){//좌로 밀기
        for(int i=0;i<n;i++){//i번째 행을 처리
            for(int j=0;j<n;j++){//미는 방향에 가까운것부터 넣어줘야됨
                if(temp[i][j]!=0){
                    drag(i,j);
                }
            }
            while(!S.empty()){
                temp[i][S.size()-1]=S.top().first;
                S.pop();
            }
        }
    }


    if(dir==2){//하
        for(int i=0;i<n;i++){//i번째 열을 처리
            for(int j=n-1;j>=0;j--){//미는 방향에 가까운것부터 넣어줘야됨
                if(temp[j][i]!=0){
                    drag(j,i);
                }
            }
            while(!S.empty()){
                temp[n-S.size()][i]=S.top().first;
                S.pop();
            }
        }
    }

    if(dir==1){//우로 밀기
        for(int i=0;i<n;i++){//i번째 행을 처리
            for(int j=n-1;j>=0;j--){//미는 방향에 가까운것부터 넣어줘야됨
                if(temp[i][j]!=0){
                    drag(i,j);
                }
            }
            while(!S.empty()){
                temp[i][n-S.size()]=S.top().first;
                S.pop();
            }
        }
    }
   
}

int main(){
    int mx=-1;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
    //1.진법으로 모든 경우의 수 구현 0,1,2,3->상,우,하,좌
    //2.각 경우의 수에 따라 이동 후 답 구하기
    for(int num=0;num<1024;num++){
        int tmp=num;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[i][j]=board[i][j];
            }
        }
        for(int j=0;j<5;j++){
            int dir=tmp%4;
            mov(dir);
            tmp/=4;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(temp[i][j]>mx)mx=temp[i][j];
            }
        }
    
    }
    cout<<mx;
}
