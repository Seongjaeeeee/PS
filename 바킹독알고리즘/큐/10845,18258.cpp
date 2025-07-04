#include<bits/stdc++.h>
using namespace std;
int arr[2000000];
int head=0;//현재 원소가 있는 칸
int tail=0;//다음에 원소가 들어갈 칸
void push(){
    int x;
    cin >> x;
    arr[tail++] = x;
}
void front(){
    if(head!=tail) cout<<arr[head]<<'\n';
    else cout << -1<<'\n';
}

void back(){
    if(head!=tail) cout<<arr[tail-1]<<'\n';
    else cout << -1<<'\n';
}

void size(){
    cout << tail-head<<'\n';
}

void empty(){
    if(head!=tail)cout<<0<<'\n';
    else cout<<1<<'\n';
}

void pop(){
    if(head!=tail) cout<<arr[head++]<<'\n';
    else cout << -1<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n>0){
        string com;
        cin >> com;
        if(com =="push") push();
        else if(com=="front") front();
        else if(com=="back") back();
        else if(com=="size") size();
        else if(com=="empty") empty();
        else if(com=="pop") pop();
        n--;
    }
    return 0;
}