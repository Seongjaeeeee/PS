#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    
    int mx=-1;
    int mul=n;
    for(int i=0;i<n;i++){
        if(mx<mul*arr[i])mx=mul*arr[i];
        mul--;
    }
    cout<<mx;
}