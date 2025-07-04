#include<bits/stdc++.h>
using namespace std;
#define max 1000000
int deq[2*max];
int head = max;//현재 원소가 있는 칸칸
int tail = max;//다음에 원소가 들어갈 탄을 가리킴
void pushfront(){
    int x;
    cin>> x;
    deq[--head]=x;
}
void pushback(){
    int x;
    cin>> x;
    deq[tail++]=x;
}
void popfront(){
    if(head==tail) cout<< -1 <<'\n';
    else cout<<deq[head++] <<'\n';
}
void popback(){
    if(head==tail) cout<< -1 <<'\n';
    else cout<<deq[--tail] <<'\n';
}
void size(){
    cout<< (tail-head) <<'\n';
}
void empty(){
    if(head==tail) cout<< 1 <<'\n';
    else cout<<0<<'\n';
}
void front(){
    if(head==tail) cout<< -1 <<'\n';
    else cout<<deq[head] <<'\n';
}
void back(){
    if(head==tail) cout<< -1 <<'\n';
    else cout<<deq[tail-1] <<'\n';
}



int main(){
    int n;
    cin >> n;
    while(n>0){
        string com;
        cin>>com;
        if(com =="push_front") pushfront();
        else if(com =="push_back") pushback();
        else if(com =="pop_front") popfront();
        else if(com =="pop_back") popback();
        else if(com =="size") size();
        else if(com =="empty") empty();
        else if(com =="front") front();
        else if(com =="back") back();
        n--;
    }
    return 0;
} 