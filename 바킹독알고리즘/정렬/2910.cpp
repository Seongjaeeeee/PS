#include<bits/stdc++.h>
using namespace std;
//별해->V자체를 stable sort를 통해 빈도에 따라 정렬하고,V를 순회하며 V의 첫번재 원소 값을 빈도 만큼 출력하면 됨
//->counting sort의 아이디어를 가져가는 간단한 풀이
vector<tuple<int,int,int>> V;//빈도체크<값,빈도,첫등장순서>
int arr[1002];//수열저장
bool cmp(int a,int b){
    int acnt,bcnt;
    int adis,bdis;
    for(auto x:V){
        if(get<0>(x)==a){
            acnt=get<1>(x);
            adis=get<2>(x);
        }
        if(get<0>(x)==b){
            bcnt=get<1>(x);
            bdis=get<2>(x);
        }
    }
    if(acnt!=bcnt)return acnt>bcnt;
    return adis<bdis;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,c;
    cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        int flag=0;
        for(auto& x:V){
            if(get<0>(x)==arr[i]){
                get<1>(x)++;
                flag=1;
                break;
            }
        }
        if(flag==0)V.push_back({arr[i],1,i});
    }
    sort(arr,arr+n,cmp);
   
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
}