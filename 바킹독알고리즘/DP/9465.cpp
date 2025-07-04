#include<bits/stdc++.h>
using namespace std;
//d[i][j]=스티커를 i열까지 채울때 j(0,1,2)행을 택했을경우 최댓값
//d[n][0]=max(d[n-1][1],d[n-1][2])
//d[n][1]=max(d[n-1][0],d[n-1][2])+stiker[1][n]
//d[n][2]=max(d[n-1][0],d[n-1][1])+stiker[2][n]
int stiker[2][100005];
int d[3][100005];
int main(){
    int iter;
    cin>>iter;
    while(iter--){
        int n;
        cin>>n;
        for(int i=0;i<2;i++){
            for(int j=1;j<=n;j++){
                cin>>stiker[i][j];
            }
        }
        d[0][1]=0;
        d[1][1]=stiker[0][1];
        d[2][1]=stiker[1][1];
        for(int i=2;i<=n;i++){
          d[0][i]=max(d[1][i-1],d[2][i-1]);
            d[1][i]=max(d[0][i-1],d[2][i-1])+stiker[0][i];
            d[2][i]=max(d[0][i-1],d[1][i-1])+stiker[1][i];
        }
        int ans=max(d[1][n],d[2][n]);
        cout<<ans<<'\n';
    }
}