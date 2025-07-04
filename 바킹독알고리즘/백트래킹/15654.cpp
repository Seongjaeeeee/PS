#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[10];
int ans[10];
int isused[10];
void func(int k){
    if(k==m){
        for(int i=0;i<m;i++){
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=0;i<n;i++){
        if(!isused[i]){
            ans[k]=arr[i];
            isused[i]=1;
            func(k+1);
            isused[i]=0;
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){//정렬
        int min = arr[i];
        int idx=i;
        for(int j=i+1;j<n;j++){
            if(min>arr[j]){
                min=arr[j];
                idx=j;
            }
        }
        int temp=arr[i];
        arr[i]=min;
        arr[idx]=temp;
    }
    func(0);

}