#include<bits/stdc++.h>
using namespace std;
//테이블 정의:d[i] = i를 1로 만들기 위한 연산 최솟값
//점화식 d[i]=min(d[i/3],d[i/2],d[i-1])
//초깃값
int d[1000002];//d[1]=0
int main(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        d[i]=d[i-1]+1;
        if(i%2==0)d[i]=min(d[i/2]+1,d[i]);
        if(i%3==0)d[i]=min(d[i/3]+1,d[i]);
    }
    cout<<d[n];
}