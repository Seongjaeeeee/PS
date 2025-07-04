#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    list<int> L;
    for(int i=1;i<=a;i++){
        L.push_back(i);
    }
    auto t = L.begin();

    int num=b;
    while(num>1){
        advance(t, 1);
        if(t==L.end()) t = L.begin();
        num--;
    }//1회차돌기기
    t = L.erase(t);
    cout<<'<'<<b;//1회차 출력력

    while(!L.empty()){
        if(t==L.end()) t = L.begin();
        int n = b;
        while(n>1){
            advance(t, 1);
            if(t==L.end()) t = L.begin();
            n--;
        }
        cout <<", "<<*t;
        t = L.erase(t);
    }
    cout<<'>';
    return 0;
}