#include<bits/stdc++.h>
using namespace std;
int stk[1000000];
int idx=0;//다음에 원소가 들어갈 인덱스

void push(){
    int x;
    cin>>x;
    stk[idx]=x;
    idx++;
    return;
}

void pop(){
    if(idx==0){
        cout<<-1<<'\n';
        return;
    }
    cout<<stk[idx-1]<<'\n';
    idx--;
    return;
}
void size(){
    cout<<idx<<'\n';
    return;
}
void empty(){
    if(idx==0)cout<<1<<'\n';
    else cout<<0<<'\n';
    return;
}
void top(){
    if(idx==0){
        cout<<-1<<'\n';
        return;
    }
    cout<<stk[idx-1]<<'\n';
    return;
}



int main(){
    int n;
    cin >>n;
    for(int i=0;i<n;i++){
        string comm;
        cin >> comm;
        if(comm == "push") push();
        else if(comm=="pop") pop();
        else if(comm=="top") top();
        else if(comm=="empty") empty();
        else if(comm=="size") size();
    }
    return 0;
}