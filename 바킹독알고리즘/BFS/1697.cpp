#include<bits/stdc++.h>
//1차원 배열에서도 최단기리를 구하기 위해 bfs응용가능->bfs를 돌려 시작점으로부터 모든칸에 접근하는 최소 시간을 얻을 수 있으므로
//주의)수빈이가 이동중 0~100000범위를 넘어갔다 오는것도 가능은 함-> 근데 이동이 비효율적이라 이 문제에서 고려할 필요는 x
using namespace std;
int main(){
    int arr[100002];
    int start,target;
    cin >> start >> target;
    int step[100002];
    for(int i=0;i<100002;i++) step[i]=-1;

    queue<int> Q;
    Q.push(start);
    step[start]=0;

    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        int a=cur+1;
        if(a>=0&&a<=100000&&step[a]==-1){
            step[a]=step[cur]+1;
            Q.push(a);
        }
        a=cur-1;
        if(a>=0&&a<=100000&&step[a]==-1){
            step[a]=step[cur]+1;
            Q.push(a);
        }
        a=cur*2;
        if(a>=0&&a<=100000&&step[a]==-1){
            step[a]=step[cur]+1;
            Q.push(a);
        }
    }

    
    cout<<step[target];
   
    return 0;
}