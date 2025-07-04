#include<bits/stdc++.h>
using namespace std;
int arr[100][100];
void quad(int size,int row,int col){//해당사이즈의 쿼드트리 출력->되면 출력,안되면 괄호열고 재귀 괄호닫기
    int check=arr[row][col];
    if(size==1){
        cout<<check;
        return;
    }
    for(int i=row;i<row+size;i++){
        for(int j=col;j<col+size;j++){
            if(arr[i][j]!=check){
                size=size/2;
                cout<<'(';
                quad(size,row,col);
                quad(size,row,col+size);
                quad(size,row+size,col);
                quad(size,row+size,col+size);
                cout<<')';
                return;
            }
        }
    }
    cout<<check;
    return;

}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        for(int j=0;j<n;j++){
            arr[i][j]=temp[j]-'0';
        }
    }
    quad(n,0,0);
}