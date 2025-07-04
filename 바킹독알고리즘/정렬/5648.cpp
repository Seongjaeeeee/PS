#include<bits/stdc++.h>
using namespace std;
//reverse(st.begin(), st.end()); 함수 이미 존재,이거쓰면됨
long arr[1000002];

long reverse(string& number){
    for(int i=0;i<number.length()/2;i++){
        swap(number[i],number[number.length()-i-1]);
    }
    return stol(number);

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        arr[i]=reverse(temp);
    }

    sort(arr,arr+n);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<'\n';
    }
}