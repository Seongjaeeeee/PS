#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int cnt=0;
    while(n>0){
        string input;
        cin >> input;
        stack<char> S;
        int noflag=0;
        for(int i=0;i<input.length();i++){
            if(input[i]=='(') S.push(input[i]);
            else {// ')'
                if(S.empty()/*||S.top()!='('*/) {
                    noflag=1;
                    break;
                }
                S.pop();
            }
        }
        n--;
        if(noflag==1) {
            cout<<"NO"<<'\n';
            continue;
        }
        if(S.empty()) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}