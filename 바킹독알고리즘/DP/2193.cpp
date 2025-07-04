#include<bits/stdc++.h>
using namespace std;
//dp[i][j]=i번째에 j를 택했을때 i자리의 이친수 개수
//dp[n][1]=dp[n-1][0]
//dp[n][0]=dp[n-1][0]+dp[n-1][1]
long long dp[100][2];
int main(){
    int n;
    cin>>n;
    dp[1][0]=0;
    dp[1][1]=1;
    for(int i=2;i<=n;i++){
        dp[i][0]=dp[i-1][1]+dp[i-1][0];
        dp[i][1]=dp[i-1][0];
    }
    cout<<dp[n][1]+dp[n][0];
}