#include<bits/stdc++.h>
using namespace std;
#define m 1000000000
//d[i][j]=i까지 j로 끝나는 것의 개수
int d[105][10];//이걸 걍 long long으로 선언하는게 편할듯
int main(){
    int n;
    cin>>n;
    for(int j=1;j<10;j++){
        d[1][j]=1;     
    }//초기값 세팅

    for(int i=2;i<=n;i++){
        for(int j=0;j<10;j++){
            if(j==0) d[i][j]=d[i-1][1]%m;
            else if(j==9) d[i][j]=d[i-1][8]%m;
            else d[i][j]=(d[i-1][j+1]%m+d[i-1][j-1]%m)%m;
        }
    }

    int ans=0;
    for(int j=0;j<10;j++){
        ans+=d[n][j]%m;
        ans%=m;
    }
    cout<<ans;
}