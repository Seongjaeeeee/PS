#include<bits/stdc++.h>
using namespace std;
int a[55];
int b[55];
int n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=a[i]*b[n-i-1];
    }
    cout<<ans;
}