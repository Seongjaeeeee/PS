#include<bits/stdc++.h>
using namespace std;
long long arr[100002];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    
    int maxsucc=1;//무조건 하나는 연속됨
    long long ans=arr[0];//모두 한번씩만 연속 되었을 때 답

    long long before=arr[0];
    int succ=1;
    for(int i=1;i<n;i++){
        if(arr[i]==before)succ++;
        else{
            succ=1;
        }//연속성 판단

        if(succ>maxsucc){
            maxsucc=succ;
            ans=arr[i];
        }//가장 오래 연속된거 찾기

        before=arr[i];//update
    }
    cout<<ans;
}