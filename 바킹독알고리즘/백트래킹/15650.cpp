#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[10];
void func(int k,int j){//k는 현재 배열에 들어있는 수 개수       j는쓸수있는수
    if(k==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=j;i<=n;i++){
        arr[k]=i;
        func(k+1,i+1);
    }
    return;
}
int main(){
    cin>>n>>m;
    func(0,1);
}


//################################## 이런 풀이도 가능
int N, M;
vector<int> a;

int main(void){
  cin >> N >> M;
  // M의 개수만큼 0을 넣어줌->조합
  for(int i = 0; i < N; ++i){
    a.push_back(i < M ? 0 : 1);
  } 
  do{
    for(int i = 0; i < N; ++i)
      if(a[i] == 0) cout << i+1 << ' ';
    cout << '\n';
  }while(next_permutation(a.begin(), a.end()));
}