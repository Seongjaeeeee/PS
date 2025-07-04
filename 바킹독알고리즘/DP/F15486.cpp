#include<bits/stdc++.h>
using namespace std;
//d[i]=i번재 날에 일을 시작했을때 최댓값
//d[i]=max(일을 할수 있을때 할 경우,일을 안할경우)
int p[1500002];
int t[1500002];
int d[1500002];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i]>>p[i];
    }
    if(t[n]==1)d[n]=p[n];
    for(int i=n-1;i>=1;i--){
        d[i]=d[i+1];//현재칸의 일을 안할경우 달라지는게 없음
        if(i+t[i]-1<=n)d[i]=max(d[i],d[i+t[i]]+p[i]);//일을 할 경우
    }
    cout<<d[1];
}