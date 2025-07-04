#include<bits/stdc++.h>
using namespace std;
pair<int,int> arr[10];
int isbroken[10];
int n;
int mx=-1;
void func(int k){
    if(k==n){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(isbroken[i]==1)cnt++;
        }
        if(cnt>mx) mx=cnt;
        return;
    }

    if(isbroken[k]==1){//손에든게꺠짐
        func(k+1);
        return;//이걸 해줘야됨 항상...
    }

    int endflag=0;
    for(int i=0;i<n;i++){//깰거
        if(!isbroken[i]&&i!=k){
            endflag=1;
            int a=arr[i].first;
            int b=arr[k].first;

            arr[i].first-=arr[k].second;
            if(arr[i].first<=0)isbroken[i]=1;
            arr[k].first-=arr[i].second;
            if(arr[k].first<=0)isbroken[k]=1;

            func(k+1);

            isbroken[i]=0;
            isbroken[k]=0;
            arr[i].first=a;
            arr[k].first=b;
        }
    }
    if(endflag==0)func(k+1);//전부깨진상태
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i].first;//내구도
        cin>>arr[i].second;//무게
    }
    func(0);
    cout<<mx;
}