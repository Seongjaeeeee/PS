#include<bits/stdc++.h>
using namespace std;
int arr[2187][2187];
int ans[3];

void cnt(int size,int row,int col){//함수정의:주어진 점에서 주어진 크기만큼이이 하나의 색종이가 맞는지 확인하는 함수
    if(size==1){
        ans[arr[row][col]+1]++;
        return;
    }
    int k=arr[row][col];
    for(int i=row;i<row+size;i++){
        for(int j=col;j<col+size;j++){
            if(arr[i][j]!=k){//재귀식:주어진크기의 배열전체를 확인 맞으면 ++,아니면 재귀를 더 작은 size의 9개 지점에 대해;
                size=size/3;
                cnt(size,row,col);cnt(size,row,col+size);cnt(size,row,col+2*size);
                cnt(size,row+size,col);cnt(size,row+size,col+size);cnt(size,row+size,col+2*size);
                cnt(size,row+2*size,col);cnt(size,row+2*size,col+size);cnt(size,row+2*size,col+2*size);
                return;
            }
        }
    }
    ans[k+1]++;
}




int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cnt(n,0,0);
    cout<<ans[0]<<'\n'<<ans[1]<<'\n'<<ans[2];
}