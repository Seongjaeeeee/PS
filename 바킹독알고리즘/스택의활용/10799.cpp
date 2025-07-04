#include<bits/stdc++.h>
using namespace std;
int main(){
    string pipe;
    cin >> pipe;
    int cnt=0;
    stack<char> S;
    S.push(pipe[0]);
    for(int i=1;i<pipe.length();i++){
        if(pipe[i]=='(') S.push(pipe[i]);
        else{// ')'
            if(pipe[i-1]=='('){//레이저
                S.pop();
                cnt+=S.size();
            }
            else{
                S.pop();
                cnt++;//마지막 조각
            }
        }
    }
    cout<<cnt;
    return 0;
}
