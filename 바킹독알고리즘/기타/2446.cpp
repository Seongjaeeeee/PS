#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=0;i<2*n-1;i++){
        if(i<n){
            for(int k=0;k<i;k++)cout<<" ";
            for(int j=0;j<2*n-1-i*2;j++){
                cout << "*";
            }
        }
        
        
        else{
            for(int k=0;k<2*n-1-i-1;k++)cout<<" ";
            for(int j=0;j<(i+1-n)*2+1;j++){
                cout << "*";
            }
        }
        

        cout << "\n";
    }
    return 0;
}