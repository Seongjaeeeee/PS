#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int> S;
    int k;
    cin >> k;
    for(int i=0;i<k;i++){
        int n;
        cin>>n;
        if(n==0){
            S.pop();
        }
        else S.push(n);
    }
    int cnt=0;
    int num = S.size();//주의ㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣㅣ
    for(int i=0;i<num;i++){
        cnt += S.top();
        S.pop();
    }
    cout<<cnt;
    return 0;

}