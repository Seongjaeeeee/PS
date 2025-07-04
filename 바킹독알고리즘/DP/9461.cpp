#include<bits/stdc++.h>
using namespace std;
long long d[150];
int main(){
    int iter;
    cin>>iter;
    d[1]=d[2]=d[3]=1;
    for(int i=4;i<=100;i++){
        d[i]=d[i-2]+d[i-3];
    }
    while(iter--){
        int n;
        cin>>n;
        cout<<d[n]<<'\n';
    }
}