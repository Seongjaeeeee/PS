#include<bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        string sentence;
        getline(cin,sentence);
        if(sentence.length()==1&&sentence[0]=='.') break;
        stack<char> S;
        int noflag=0;
        for(int i=0;i<sentence.length();i++){
            if(sentence[i]=='['||sentence[i]=='(') S.push(sentence[i]);
            else if(sentence[i]==']'){//닫기는 여는걸 뽑아내는 명령어임)->원래라면 무조건 닫기 나오면 쌍이 맞는게 top에 있어야 함
                if(S.empty()||S.top()!='['){//비어있는데 닫을경우,쌍이 맞지 않을경우
                    noflag=1;
                    break;
                }
                S.pop();
            }
            else if(sentence[i]==')'){
                if(S.empty()||S.top()!='('){//비어있는데 닫을경우 바로처리
                    noflag=1;
                    break;
                }
                S.pop();
            }
        }
        if(noflag==1){
            cout<<"no"<<'\n';
            continue;
        }
        if(S.empty())cout<<"yes"<<'\n';
        else cout<<"no"<<'\n';
    }
    return 0;
}