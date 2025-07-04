#include<bits/stdc++.h>
using namespace std;
int isused1[20];//열
int isused2[40];//오른쪽위 대각선->x+y
int isused3[40];//오른쪽아래->x-y+(n-1)
int n;
int cnt;
void func(int k){//k는 놓은 queen의 개수,queen을 놓을 행의 인덱스
    if(k==n){
        cnt++;
        return;
    } 
    for(int i=0;i<n;i++){//놓을 열 탐색
        if(!isused1[i]&&!isused2[i+k]&&!isused3[k-i+n-1]){
            isused1[i]=1;
            isused2[i+k]=1;
            isused3[k-i+n-1]=1;
            func(k+1);
            isused1[i]=0;
            isused2[i+k]=0;
            isused3[k-i+n-1]=0;
        }
    }

}

int main(){
    cin>>n;
    func(0);
    cout<<cnt;
}