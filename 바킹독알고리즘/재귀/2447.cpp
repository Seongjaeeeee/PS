#include<bits/stdc++.h>
using namespace std;
char arr[2500][2500];
void star(int size,int row,int col){//공백뚫는함수->더 작은범위로 재귀
    if(size==1)return;
    int k=size/3;
    for(int i=row+k;i<row+2*k;i++){
        for(int j=col+k;j<col+2*k;j++){
            arr[i][j]=' ';
        }
    }
    star(k,row,col);star(k,row,col+k);star(k,row,col+2*k);
    star(k,row+k,col);star(k,row+k,col+2*k);
    star(k,row+2*k,col);star(k,row+2*k,col+k);star(k,row+2*k,col+2*k);
}
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]='*';
        }
    }
    star(n,0,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j];
        }
        cout<<'\n';
    }
}