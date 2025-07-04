#include<bits/stdc++.h>
using namespace std;
//dp[i]=i로 끝나는 부분 증가 수열중 가장 긴것의 길이
//dp[n]=dp[k]+1(arr[n]>arr[k]인것 중 dp[k]가 max인것)
int arr[1002];
int dp[1002];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    dp[0]=1;
    for(int i=1;i<n;i++){
        int mx=0;
        for(int j=i-1;j>=0;j--){
            if(arr[i]>arr[j]){
                if(dp[j]>mx){
                    mx=dp[j];
                }
            }
        }
        dp[i]=mx+1;
    }

    int mx=1;
    for(int i=0;i<n;i++){
        if(mx<dp[i])mx=dp[i];
    }
    cout<<mx;
}