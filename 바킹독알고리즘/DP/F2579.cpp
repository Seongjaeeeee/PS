#include<bits/stdc++.h>
using namespace std;
//d[i] i번째 칸까지 도착해야 할때 최댓값
//d[i]=max(d[i-2]+score[i],d[i-3]+score[i-1]+score[i])
//바로직전의 d[i-1]을사용하면 이것이 2연속인 최댓값일때 d[i]에 이 값을 사용 불가능,대신 직전의 계단 택할 겅우 d[i-3] 사용
//초깃값 d[1],d[2]

/*별해
d[i][j]->i까지 도착할때 j번 연속으로 께단을 밟고 왔을때 최댓값 -> d[i][1]은 1번,i만 밟을때  d[i][2]는 i-1도 밟고 왔을때 최댓값 사용가능
d[n][1]=max(d[n-2][1],d[n-2][2])+score[i]
d[n][2]=d[n-1][1]+score[i]

답은 max(d[n][1],d[n][2])
*/
int d[302];//max,연속횟수 저장
int score[302];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>score[i];
    }
    d[0]=0;
    d[1]=score[1];
    d[2]=score[1]+score[2];
    d[3]=max(score[1],score[2])+score[3];
    
    for(int i=4;i<=n;i++){
        d[i]=max(d[i-2],d[i-3]+score[i-1])+score[i];
    }
    cout<<d[n];
}