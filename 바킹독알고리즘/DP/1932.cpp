#include<bits/stdc++.h>
using namespace std;
int arr[502][502];
int dp[502][502];//각각의 칸(dp[i][j])까지 점수의 최대 값
//dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+arr[i][j];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cin>>arr[i][j];
            if(j==0){
                if(i==0) dp[i][j]=arr[i][j];
                else dp[i][j]=dp[i-1][j]+arr[i][j];
            }//초깃값 설정(첫열)
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<i+1;j++){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+arr[i][j];//가장 오른쪽 값들은 예외로 dp[i-1][j]가 없지만 얘네는 다 0이므로 자동으로 선택이 안되기에 따로 처리 x
        }
    }
    
    int ans=-1;
    for(int i=0;i<n;i++){
        if(dp[n-1][i]>ans)ans=dp[n-1][i];
    }
    cout<<ans;
}