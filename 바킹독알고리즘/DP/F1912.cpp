#include<bits/stdc++.h>
using namespace std;
/*** 카데인 알고리즘 ***/
//dp[i]=i번째 타일로 끝나는 최대 sub array -> 각각의 배열 요소로 끝나는 모든 sub array가 dp에 저장 -> dp에서 max찾으면 됨
//dp[n]=max(dp[n-1],0)+arr[n] 
//->이전까지의 최대 연속 합이 0보다 작으면,그냥 현재것만 가져가는게 나음
//->이전까지 최대 연속 합이 0보다 크면 거기에 현재것을 더하는게 무조건 큼
int arr[100002];
int dp[100002];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dp[0]=arr[0];
    for(int i=1;i<n;i++){
        dp[i]=max(0,dp[i-1])+arr[i];
    }
    int mx=dp[0];
    for(int i=0;i<n;i++){
        if(dp[i]>mx)mx=dp[i];
    }
    cout<<mx;
}