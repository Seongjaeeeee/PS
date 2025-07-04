#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    deque<int> deq;
    for(int i=1;i<=n;i++){
        deq.push_back(i);
    }
    int answer=0;
    while(m>0){
        int target;
        cin>>target;
        auto t = deq.begin();
        auto it = find(deq.begin(), deq.end(), target);
        int num=it-t;
        answer += min(int(deq.size()-num),num);//답 계산
        while(num>0){
            int temp;
            temp=deq.front();
            deq.pop_front();
            deq.push_back(temp);
            num--;
        }
        deq.pop_front();//큐 상태 유지 구현
        m--;
    }
    cout<<answer;
    return 0;
}