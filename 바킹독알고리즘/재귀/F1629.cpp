#include<bits/stdc++.h>
using namespace std;
//시간복잡도초과 O(b)는 b땜에 발생->b를 줄이자      (a%m * b%m)%m == ab%m 원리 이용 ->(a^(b/2)%c)*(a^(b/2)%c)%c == a^b%c
//함수정의 -> a^b%c계산 함수
//base ->b=1일때 즉,a%c
//재귀식 -> mul(a,b/2,c)*mul(a,b/2,c)%c가 원래 mul(a,b,c)와 같다(홀수는 따로처리)
long long mul(long long a,long long b,long long c){
    if(b==1) return a%c;
    long long val = mul(a,b/2,c);//이렇게 해서 mul두번 호출하지 않고 횟수 줄이기
    val=val*val%c;
    if(b%2==1) return val*a%c;//val * val * a % c; 이딴식으로 한번에 푸려고 하면 integer overflow발생
    return val;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a,b,c;
    cin>>a>>b>>c;
    cout<<mul(a,b,c);
    return 0;
}

//사고->base codition a^1 mod c -> o(1)
//a^k mod c --> a^2k mod c (a^2k+1 mod c)-> o(1)
//위 과정을 보면 귀납적으로 base에서 목표까지 도달가능->수학적 귀납법같은 접근
