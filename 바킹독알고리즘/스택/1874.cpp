#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> V(n);
    for(int i=0;i<n;i++){
        cin >> V[i];//목표 수열
    }

    int insertnum=1;
    int vectoridx=0;
    stack<int> S;
    vector<char> printV(2*n);
    for(int i=0;i<2*n;i++){
        if(!S.empty()){
            if(S.top()==V[vectoridx]){
                printV[i]='-';
                S.pop();
                vectoridx++;
            }
            else{
                S.push(insertnum);
                insertnum++;
                printV[i]='+';
            }
        }
        else{
            S.push(insertnum);
            insertnum++;
            printV[i]='+';

        }

    }
    if(!S.empty())cout<<"NO";
    else{
        for(int i=0;i<2*n;i++){
            cout<<printV[i]<<'\n';
        }
    }
    return 0;
}