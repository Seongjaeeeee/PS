#include<bits/stdc++.h>
/*기본적인 괄호문제의 응용
가장 작은 단위에 대해서만 계산을 하면 된다는게 포인트(),[]
지금 열려있는 stack의 값에 대해 생각 -> 10799 쇠막대기 문제와 비슷*/
using namespace std;
int main(){
    string path;
    cin >> path;
    int err=0;
    stack<char> S;
    int answer=0;
    int stackMul=1;
    for(int i=0;i<path.length();i++){
        if(path[i]=='('){
            S.push(path[i]);
            stackMul*=2;
        }
        else if(path[i]=='['){
            S.push(path[i]);
            stackMul*=3;
        }
        else if(path[i]==')'){
            if(S.empty()||S.top()!='('){//올바른지 체크
                err=1;
                break;
            }
            S.pop();
            if(path[i-1]=='(') answer+=stackMul;
            stackMul/=2;
        }
        else if(path[i]=']'){
            if(S.empty()||S.top()!='['){//올바른지 체크
                err=1;
                break;
            }
            S.pop();
            if(path[i-1]=='[')answer+=stackMul;
            stackMul/=3;
        }
    }
    if(!S.empty()||err==1){
        cout<<0;
    } 
    else{
        cout<<answer;
    }
    
    return 0;
}
