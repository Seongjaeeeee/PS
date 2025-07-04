#include<bits/stdc++.h>
using namespace std;
int n,m;
int isused[10];//현재 숫자의 사용여부
int arr[10];//답을 넣을 상태 배열
void func(int k){//배열의 k번째를 채우자
    if(k==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){//i는 배열에 들어갈 숫자들
        if(!isused[i]){
            arr[k]=i;
            isused[i]=1;
            func(k+1);
            isused[i]=0;
        }
    }
}

int main(){
    cin>>n>>m;
    func(0);
    return 0;
}   

//################################## 이런 풀이도 가능
#include<bits/stdc++.h>
using namespace std;
int N, M;
int check[10];
vector<int> a;

int main(void){
  cin >> N >> M;
  for(int i = 1; i <= N; i++){
    a.push_back(i);
  }

  do{
    int flag=0;
    for(int i = 0; i < M; i++){
        if(check[i]==a[i]) flag++;
    }
    if(flag!=M){//중복제외
        for(int i = 0; i < M; i++){
            check[i]=a[i];
            cout<<a[i]<<' ';
        }
        cout<<'\n';
    }
    
  }while(next_permutation(a.begin(), a.end()));
}