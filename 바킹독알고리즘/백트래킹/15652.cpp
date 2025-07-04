#include<bits/stdc++.h>
using namespace std;
int arr[10];
int n,m;
void func(int k,int j){
    if(k==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=j;i<=n;i++){
        arr[k]=i;
        func(k+1,i);
    }

}

int main(){
    cin>>n>>m;
    func(0,1);
}