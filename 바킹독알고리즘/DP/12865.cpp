#include<bits/stdc++.h>
using namespace std;
//d[i][j]=i번째 물건을 담을지 말지 판단할때 가방의 용량이 j라면 담을수있는 최대 가치->하나씩 담을지 말지 판단하면서 다음줄로 내려가는것
//d[i][j]=max(d[i-1][j],d[i-1][j-weight]+val) // 그냥 못담는 상황이면 d[i-1][j]
//초깃값은 0번째 행과 0번째 열 전부 0으로 세팅
pair<int,int> item[105];
int d[105][100005];
int main(){
    int n,k;//물건개수, 용량
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>item[i].first>>item[i].second;//무게,가치
    }

    for(int i=1;i<=n;i++){//첫번째부터 n번째 물건까지
        for(int j=1;j<=k;j++){//용량
            if(j-item[i].first>=0){
                d[i][j]=max(d[i-1][j],d[i-1][j-item[i].first]+item[i].second);
            }
            else d[i][j]=d[i-1][j];
        }
    }
    cout<<d[n][k];    
}