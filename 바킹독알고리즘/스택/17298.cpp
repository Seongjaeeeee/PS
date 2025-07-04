#include<bits/stdc++.h>
/*stack -> 오큰수가 될수있는 후보 
오른쪽을 반드시 알아야 문풀가능 -> 오른쪽부터 stack에넣으며 판단
현재 보는 값보다 작은값은 앞으로 오큰수 가능성 0이므로 pop해도 됨 top에 큰값 나올때까지
현재 보는 값보다 큰값이 stack에나온다? -> 오큰수
*/
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr;
    while(n>0){
        int t;
        cin >> t;
        arr.push_back(t);
        n--;
    }

    vector<int> answerV;
    stack<int> S;
    for(int i=arr.size()-1;i>=0;i--){
        if(S.empty()){
            S.push(arr[i]);
            answerV.push_back(-1);
        }
        else{
            while(!S.empty()&&S.top()<=arr[i]){
                S.pop();
            }
            if(!S.empty()){
                answerV.push_back(S.top());
            }
            else answerV.push_back(-1);
            S.push(arr[i]);
        }
    }

    for(int i=answerV.size()-1;i>=0;i--){
        cout <<answerV[i]<<' ';
    }
    
    return 0;
}