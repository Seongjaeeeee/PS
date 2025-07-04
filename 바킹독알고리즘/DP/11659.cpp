#include<bits/stdc++.h>
using namespace std;
//prefix sum
int arr[100002];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    cin>>arr[1];
    for(int i=2;i<=n;i++){
        cin>>arr[i];
        arr[i]=arr[i]+arr[i-1];
    }
    while(m--){
        int i,j;
        cin>>i>>j;
        cout<<arr[j]-arr[i-1]<<'\n';
    }  
    return 0;
}