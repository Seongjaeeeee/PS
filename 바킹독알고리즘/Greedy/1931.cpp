#include<bits/stdc++.h>
using namespace std;
//귀류법을 생각해보자
//가능한것중 가장 먼저 끝나는걸 선택하지 않았을때 더 많이 회의실을 배정할수 있다->모순->가장 먼저 끝나는걸 선택하는게 최적

//지금 당장 손해를 보더라도 나중가서 이득인 경우가 있을지 고민하는게 그리디에서 도움된다(그런 경우가 없으면 그리디가 최적)
bool cmp(pair<int,int>& a,pair<int,int>& b){
    if(a.second!=b.second)return a.second<b.second;
    return a.first<b.first;//시작하자마자 끝나는 경우가 있기에 끝나는 시간이 같으면 시작하는게 빠른 순으로 정렬 
}
pair<int,int> arr[100005];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    
    sort(arr,arr+n,cmp);//끝나는 시간이 빠른순으로 정렬

    int cnt=1;//첫회의
    int curend=arr[0].second;
    for(int i=1;i<n;i++){
        if(curend<=arr[i].first){
            cnt++;
            curend=arr[i].second;
        } 
    }
    cout<<cnt;
} 