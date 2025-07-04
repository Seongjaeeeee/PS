#include<bits/stdc++.h>
using namespace std;
string arr[100];
bool cmp(const string& a,const string& b){//a가 앞에와야될때 true 반환,주의 -> 둘이 우선순위가 같을때는 false를 반환해야됨
    if(a.length()!=b.length()) return a.length()<b.length();
    int numa=0;
    int numb=0;
    for(int i=0;i<a.length();i++){
        if(a[i]-'0'>=0&&a[i]-'0'<=9) numa+=a[i]-'0';
    }
    for(int i=0;i<b.length();i++){
        if(b[i]-'0'>=0&&b[i]-'0'<=9) numb+=b[i]-'0';
    }
    if(numa!=numb)return numa<numb;
    return a<b;
}
int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr,arr+N,cmp);
    for(int i=0;i<N;i++){
        cout<<arr[i]<<'\n';
    }
    return 0;
}