#include<bits/stdc++.h>
using namespace std;
int ans[10];
int arr[20];
int n;
void func(int k,int j){
    if(k==6){
        for(int i=0;i<6;i++){
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
    }
    for(int i=j;i<n;i++){
        ans[k]=arr[i];
        func(k+1,i+1);
    }
}
int main(){
    while(1){
        cin>>n;
        if(n==0)break;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        func(0,0);
        cout<<'\n';
    }
    return 0;
}