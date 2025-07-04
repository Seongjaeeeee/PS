#include<bits/stdc++.h>
using namespace std;
//d[i][j]->i번째에서 j를 선택할때 거리를 i까지 채우는 최소비용
//모든 값을 유지할 필요 있음
//d[n][j]=min(d[n-1][!j]+color[n][0])
int color[1002][3];
int dp[1002][3];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>color[i][0]>>color[i][1]>>color[i][2];
    }
    dp[0][0]=color[0][0];
    dp[0][1]=color[0][1];
    dp[0][2]=color[0][2];
    for(int i=1;i<n;i++){
        dp[i][0]=min(dp[i-1][1],dp[i-1][2])+color[i][0];
        dp[i][1]=min(dp[i-1][0],dp[i-1][2])+color[i][1];
        dp[i][2]=min(dp[i-1][0],dp[i-1][1])+color[i][2];
    }
    int ans=min(dp[n-1][0],dp[n-1][1]);
    ans=min(ans,dp[n-1][2]);
    cout<<ans;
}
