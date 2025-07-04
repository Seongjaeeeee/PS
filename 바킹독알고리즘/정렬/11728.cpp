#include<bits/stdc++.h>
using namespace std;
int arr1[1000002];
int arr2[1000002];
int arr3[1000002];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }

    int idx1=0;
    int idx2=0;
    for(int i=0;i<n+m;i++){
        if(idx1==n){
            arr3[i]=arr2[idx2++];
        }
        else if(idx2==m){//idx1==m이면서 idx2==n인 경우는 불가능 i<n+m에 걸림,
            arr3[i]=arr1[idx1++];
        }
        else if(arr1[idx1]<=arr2[idx2]){//stable유지하기 위해 같을땐 1번 배열(앞쪽 배열)원소 넣기
            arr3[i]=arr1[idx1++];
        }
        else{
            arr3[i]=arr2[idx2++];
        }    
        cout<<arr3[i]<<' ';
    }
}