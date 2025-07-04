#include<bits/stdc++.h>
using namespace std;
int arrn[20002];//a보다 작은 것을 먹을 수 있다
int arrm[20002];//b
//둘 다 정렬
//->a를 작은것부터 탐색+b를 탐색하면서 a보다 작은것까지 count
//count는 계속 누적시키며 탐색->탐색끝나면 ans에 count를 더해줌
//a,b둘다 한번 선형 탐색으로 끝
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int iter;
    cin>>iter;
    while(iter--){
        int ans=0;
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>arrn[i];
        }
        for(int i=0;i<m;i++){
            cin>>arrm[i];
        }
        sort(arrn,arrn+n);
        sort(arrm,arrm+m);

        
        int bidx=0;//b를 탐색+count역할
        for(int i=0;i<n;i++){
            while(arrm[bidx]<arrn[i]&&bidx!=m){
                bidx++;
            }
            ans+=bidx;
        }
        cout<<ans<<'\n';
    }
}
