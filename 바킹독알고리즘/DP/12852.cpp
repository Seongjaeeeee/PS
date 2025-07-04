#include<bits/stdc++.h>
using namespace std;
//dp[i]=i를 0으로 만들때 필요한 최솟값
//dp[n]=min(dp[n-1],dp[n/2],dp[n/3])
//초기값 d[1]=0
//pre배열을 통해 경로 추적
int dp[1000002];
int pre[1000002];
int main(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+1;
        pre[i]=i-1;
        if(i%2==0){
            if(dp[i/2]+1<dp[i]){
                dp[i]=dp[i/2]+1;
                pre[i]=i/2;
            }
        }
        if(i%3==0){
            if(dp[i/3]+1<dp[i]){
                dp[i]=dp[i/3]+1;
                pre[i]=i/3;
            }
        }
    }
    cout<<dp[n]<<'\n';
    int i=n;
    while(i!=0){
        cout<<i<<' ';
        i=pre[i];
    }
}