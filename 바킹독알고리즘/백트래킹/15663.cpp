#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[10];
int ans[10];
int isused[10];

void func(int k){
    int pop=1000000;
    if(k==m){
        for(int i=0;i<m;i++){
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=0;i<n;i++){
        if(!isused[i]&&!(arr[i]==pop)){
            ans[k]=arr[i];
            isused[i]=1;
            func(k+1);
            isused[i]=0;
            pop=arr[i];
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    func(0);

}