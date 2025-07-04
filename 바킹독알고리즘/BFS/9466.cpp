#include<bits/stdc++.h>
using namespace std;
//bfs,dfs 라기보단 사이클을 판단하는 알고리즘 문제임
//https://blog.encrypted.gg/499 ->이미 방문한 원소x를 재 방문하면 x까지 한바퀴 더 돌려서 사이클에 드가있는 요소를 판단하는 기법 사용
//나는 이미 스택에 있는 원소x를 재 방문하면 그 원소까지 pop하고 pop한것들은 사이클이다라는 논리를 사용
int main(){
    int num;
    cin>>num;
    while(num>0){
        int arr[100002];//index i와 연결된거
        int fin[100002];//index i의 판단 끝(사이클이거나 사이클 아님) 
        int isused[100002];//index i가 사용중
         
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            fin[i]=0;
            isused[i]=0;
        }
        int cnt=0;
    //이미 스택에 있는게 나올때까지 스택에 넣기
    //나오면 전부 빼주기
        stack<int> S;
        for(int i=1;i<=n;i++){//다음 덩어리 계속 탐색
            if(fin[i]==1)continue;
            S.push(i);
            isused[i]=1;
            while(!S.empty()){
                int k=S.top();
                //종료조건 1
                if(isused[arr[k]]==1){//사용중인게 또 나옴->사이클이다
                    while(S.top()!=arr[k]){//사이클 다 빼줌
                        isused[S.top()]=0;
                        fin[S.top()]=1;
                        S.pop();
                        cnt++;
                    }
                    cnt++;//top에 남아있는 하나의 값 

                    while(!S.empty()){//남은 애들은 사이클 아님 얘네도 다 빼주기
                        isused[S.top()]=0;
                        fin[S.top()]=1;
                        S.pop();
                    }
                }
                //종료조건 2
                else if(fin[arr[k]]==1){//이미 사이클이거나 사이클 아닌것에 접근->지금 스택에 있는애들은 사이클 아님
                    while(!S.empty()){
                        isused[S.top()]=0;
                        fin[S.top()]=1;
                        S.pop();
                    }
                }
                else{//종료조건 아니면 계속 push
                    S.push(arr[k]);
                    isused[arr[k]]=1;
                }   
            }
        }
        cout<<n-cnt<<'\n';
        num--;
    }
    return 0;
}