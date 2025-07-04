#include<bits/stdc++.h>
using namespace std;
//d[i]=i를 1,2,3의 합으로 나타내는 방법의 수
//d[i]=d[i-3]+d[i-2]+d[i-1];
//d[0]=0,d[1]=1,d[2]=2,d[3]=4
int d[12]={0,1,2,4};
int main(){
    int iter;
    cin>>iter;
    while(iter--){
        int n;
        cin>>n;
        for(int i=4;i<=n;i++){
            d[i]=d[i-1]+d[i-2]+d[i-3];
        }
        cout<<d[n]<<'\n';
    }
    return 0;
}