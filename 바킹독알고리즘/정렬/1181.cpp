#include<bits/stdc++.h>
using namespace std;
string arr[20002];
bool cmp(string& a,string& b){
    if(a.length()!=b.length())return a.length()<b.length();
    return a<b;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }   
    sort(arr,arr+n,cmp);
    
    string before=arr[0];
    cout<<arr[0]<<'\n';
    for(int i=1;i<n;i++){
        if(before!=arr[i])cout<<arr[i]<<'\n';
        before=arr[i];
    }   
}