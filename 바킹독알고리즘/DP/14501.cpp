#include<bits/stdc++.h>
using namespace std;
//d[i]=i번째 날까지의 최댓값
//d[i]=max(일 안했을때,d[k]+p[k]들(k는 현재날까지 일을 완수할 수 있는 상담일)))
int p[20];
int t[20];
int d[20];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i];
        cin>>p[i];
    }
    
    for(int i=1;i<=n;i++){
        d[i]=d[i-1];
        for(int j=1;j<=i;j++){
            if(i-j>=t[j]-1)d[i]=max(d[i],d[j-1]+p[j]); //j의 일이 현재 날까지 완수 가능
        }
    }
    cout<<d[n];
}