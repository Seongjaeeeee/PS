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
        for(int i=0;i<input.length();i++){
            if(S.empty()){
                S.push(input[i]);
            }
            else{
                if(S.top()==input[i]){
                    S.pop();
                }
                else S.push(input[i]);
            }
        }
        if(S.empty()) cnt++;
        n--;
    }
    cout<< cnt;
}