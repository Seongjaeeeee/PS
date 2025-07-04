#include<bits/stdc++.h>
using namespace std;
//자료형땜에 고생 answer가 1+2+..80000이 되면 넘어가는듯 -> answer만 longlong이면 되었던 문제
int main(){
    int n;
    cin >> n;
    vector<int> V;
    while(n>0){
        int num;
        cin >> num;
        V.push_back(num);
        n--;
    }
    long long answer=0;
    stack<pair<int,long long>> S;//<height,val>
    int i=V.size()-1;
    for(i;i>=0;i--){
        long long val=0;//안전빵 longlong
        while(!S.empty()&&(S.top().first<V[i])){
            val+=S.top().second+1;//본인거 기본 +1에 본인이 본게 val
            answer+=S.top().second;//pop될때 값을 답에 더하기
            S.pop();
        }
        S.push({V[i],val});
        
    }

    while(!S.empty()){
        answer+=S.top().second;
        S.pop();
    }

    cout<<answer;
    return 0;

}