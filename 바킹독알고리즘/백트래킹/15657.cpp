#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans[10];
int arr[10];
void func(int k,int j){
    if(k==m){
        for(int i=0;i<m;i++){
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=j;i<n;i++){
        ans[k]=arr[i];
        func(k+1,i);
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    func(0,0);
}