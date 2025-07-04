#include<bits/stdc++.h>
using namespace std;
//dp[i]=i로 끝나는 부분증가수열중 가장 큰 것
//dp[n]=dp[k]+arr[n](arr[k]<arr[n]중 dp[k]가 max인 k)
int arr[1002];
int dp[1002];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        dp[i]=arr[i];//기본값
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]) dp[i]=max(dp[i],dp[j]+arr[i]);
        }
    }

    int mx=dp[0];
    for(int i=0;i<n;i++){
        if(mx<dp[i])mx=dp[i];
    }
    cout<<mx;
}