#include<bits/stdc++.h>
using namespace std;
int cnt;
int ans;
void funz(int size,pair<int,int> pos,pair<int,int> tar){//정의:target이 있는 분면의 첫 주소 찾는다
    if(size==1){//종료조건: size==1이면 target 위치를 찾은것
        ans=cnt;
        return;
    }
    //재귀내용:target이 있는 분면을 찾고 분면에 따른 값계산,해당 분면의 첫 주소를 넘기며 재귀호출
    int s=size/2;
    int row=pos.first;
    int col=pos.second;
    if(row+s>tar.first&&col+s>tar.second){
        funz(s,pos,tar);
    }//1사
    if(row+s>tar.first&&col+s<=tar.second){
        cnt+=s*s;
        funz(s,{row,col+s},tar);
    }//2사
    if(row+s<=tar.first&&col+s>tar.second){
        cnt+=(s*s)*2;
        funz(s,{row+s,col},tar);
    }//3사
    if(row+s<=tar.first&&col+s<=tar.second){
        cnt+=(s*s)*3;
        funz(s,{row+s,col+s},tar);
    }//4사
}


int main(){
    int n;
    cin>>n;
    n=1<<n;

    pair<int,int> tar;
    cin>>tar.first>>tar.second;//first==row,second==col

    
    funz(n,{0,0},tar);
    cout<<ans;
    return 0;
}