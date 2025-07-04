#include<bits/stdc++.h>
using namespace std;
int arr[150][150];
int ans[2];

void paper(int size,int row,int col){//종이인지 확인하는함수 : check후 아니면면 4등분
    if(size==1){
        ans[arr[row][col]]++;
        return;
    }
    int check=arr[row][col];
    for(int i=row;i<row+size;i++){
        for(int j=col;j<col+size;j++){
            if(arr[i][j]!=check){
                size=size/2;
                paper(size,row,col);
                paper(size,row,col+size);
                paper(size,row+size,col);
                paper(size,row+size,col+size);
                return;
            }
        }
    }
    ans[check]++;
    return;
}


int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    paper(n,0,0);
    cout<<ans[0]<<'\n'<<ans[1];
    
    return 0;
}