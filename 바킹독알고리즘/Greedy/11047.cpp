//그리디 풀이 생각->증명->구현
#include<bits/stdc++.h>
using namespace std;
int arr[15];
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cnt=0;
    for(int i=n-1;i>=0;i--){
        cnt+=k/arr[i];
        k=k%arr[i]; 
    }
    cout<<cnt;
}