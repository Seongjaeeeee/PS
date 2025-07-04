#include<bits/stdc++.h> 
/*
stack에서 현재 탑을 수신할 탑(더 큰탑)을 찾을때까지 pop한 뒤 찾고나서 push
더 큰 탑 이전의 탑은 수신받을일이 없기때문에 현재 탑보다 작은 탑은 계속 pop을 해도 무관한것*/
using namespace std;
int main(){
    int n;
    cin >> n;
    stack<pair<int, int>> S;//pair 활용 -> 높이,위치
    vector<int> ansV;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        if(S.empty()){//초기
            ansV.push_back(0);
            S.push({tmp,i+1});//묶어서 넣어주기
        }
        else{
            if(tmp>S.top().first){
                while(!S.empty()&&(tmp>S.top().first)){
                    S.pop();
                }
                if(S.empty()) ansV.push_back(0);
                else ansV.push_back(S.top().second);
                S.push({tmp,i+1});
            }
            else{
                ansV.push_back(S.top().second);
                S.push({tmp,i+1});
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<ansV[i]<<' ';
    }

    return 0;
}