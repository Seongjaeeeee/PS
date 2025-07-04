#include<bits/stdc++.h>
using namespace std;
void hanoi(int n,int a,int b){//함수 정의 -> a에서b로 n개 옮기자
    if(n==1){//base정의 한개는 그냥 옮기면 되니깐 출력
        cout<<a<<' '<<b<<'\n';
        return;
    }
    hanoi(n-1,a,6-a-b);//재귀식 정의->n옮기기 위해선 n-1을 이동시키고 n옮기고 n-1다시 이동
    cout<<a<<' '<<b<<'\n';
    hanoi(n-1,6-a-b,b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    cout<<(1<<n)-1<<'\n';//2^n-1번 필요
    hanoi(n,1,3);
    return 0;
}