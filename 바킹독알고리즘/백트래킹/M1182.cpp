#include<bits/stdc++.h>
using namespace std;
//상식:원소가 n인 집합에서 부분집합개수는 2^n && 부분수열==부분집합(둘다 중복없이 뽑는것이므로)
//재귀에 가까운 풀이
int n, s;
int arr[30];
int cnt = 0;
void func(int cur, int sum){//sum은 합,cur은 현재 원소의 인덱스
  if(cur == n){
    if(sum == s) cnt++;
    return;
  }
  func(cur+1, sum);//현재 원소소 선택안하는 경우
  func(cur+1, sum+arr[cur]);//선택하는경우
}
int main(){
  cin>>n>>s;
  for(int i=0;i<n;i++){
    cin >> arr[i];
  }
  func(0, 0);
  if(s == 0) cnt--;//0일경우 공집합도 세는거 방지
  cout << cnt;
}
//아래는 내 풀이->백트래킹
/*int n,s;
int cnt;
int arr[50];

void func(int sum,int j){//j는 시작해도되는는 인덴스,sum은 현재의 합
    if(j==n)return;
    for(int i=j;i<n;i++){
      sum+=arr[i];
      if(sum==s)cnt++;
      func(sum,i+1);
      sum-=arr[i];
    }

}

int main(){
    cin>>n>>s;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    func(0,0);
    cout<<cnt;

}*/