#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    queue<int> Q;
    for(int i=1;i<=n;i++){
        Q.push(i);
    }

    while(Q.size()!=1){
        Q.pop();
        int temp = Q.front();
        Q.push(temp);
        Q.pop();
    }
    cout<<Q.front();
}