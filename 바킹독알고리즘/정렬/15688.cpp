#include<bits/stdc++.h>
using namespace std;
//O(n+k)의 counting sort 
int arr[2000005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr[temp+1000000]++;
    }

    for(int i=0;i<2000005;i++){
        while(arr[i]!=0){
            cout<<i-1000000<<'\n';
            arr[i]--;
        }
    }
    return 0;
    
}