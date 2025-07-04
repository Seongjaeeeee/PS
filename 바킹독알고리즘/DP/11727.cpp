#include<bits/stdc++.h>
using namespace std;
//dp[i]=i번째 타일까지 채우는 방법의 수
//dp[n]=dp[n-1]+dp[n-2]*2
int dp[1002];
int main(){
    int n;
    cin>>n;
    dp[1]=1;
    dp[2]=3;
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2]*2)%10007;///이렇게 안하면 중간에 int overflow가 생기므로 미리 나눠주자
    }
    cout<<dp[n];
}
