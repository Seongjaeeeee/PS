#include<bits/stdc++.h>
using namespace std;
int arr[10];
int n,m;

void func(int k){//k는 지금넣을 칸의 index
    if(k==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){
        arr[k]=i;
        func(k+1);
    }
}

int main(){
    cin>>n>>m;
    func(0);
}