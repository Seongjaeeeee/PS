#include<bits/stdc++.h>
using namespace std;
char arr[3100][6200];
void tri(int h,int row,int col){//구멍뚫기->재귀 좌표주기
    if(h==3){
        arr[row+1][col]=' ';
        return;
    }
    int k=0;
    for(int i=row+h/2;i<row+h;i++){//구멍뚫기
        for(int j=(col-h/2)+(k+1);j<((col-h/2)+(k+1))+(h-1)-2*k;j++){
            arr[i][j]=' ';
        }
        k++;
    }
    tri(h/2,row,col);
    tri(h/2,row+h/2,col-h/2);
    tri(h/2,row+h/2,col+h/2);
}
int main(){
    int n;
    cin>>n;//->높이
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++){
            arr[i][j]=' ';
        }
        for(int j=n-i-1;j<(n-i-1)+2*(i+1)-1;j++){//별의 시작좌표는 23,22,21...(n-1부터 하나씩 줄음)
            arr[i][j]='*';
        }
    }

    tri(n,0,n-1);

    for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++){
            cout<<arr[i][j];
        }
        cout<<'\n';
    }
}