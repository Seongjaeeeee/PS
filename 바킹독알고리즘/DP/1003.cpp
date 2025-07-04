#include<bits/stdc++.h>
using namespace std;
int dp0[50];//dp0[i]는 i번째 피보나치가 0을 쓰는 횟수
int dp1[50];//dp1[i]는 i번째 피보나치가 1을 쓰는 횟수
//재귀식 dp[i]=dp[i-2]+dp[i-1]
int main(){
    int iter;
    cin>>iter;
    dp0[0]=1;
    dp1[0]=0;
    dp0[1]=0;
    dp1[1]=1;
    for(int i=2;i<=40;i++){
        dp0[i]=dp0[i-1]+dp0[i-2];
        dp1[i]=dp1[i-1]+dp1[i-2];
    }
    while(iter--){
        int n;
        cin>>n;  
        cout<<dp0[n]<<' '<<dp1[n]<<'\n';
    }
}