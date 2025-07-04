#include<bits/stdc++.h>
using namespace std;
//구현은 쉬운데 파싱이 어렵 ㅋ
void parser(int num, deque<int>& dq){
    string input;
    cin >> input;
    input[input.length()-1]=',';
    int cur=0;
    for(int i=1;i<input.length();i++){
        if(input[i]==','&&i!=1) {
            dq.push_back(cur);
            cur=0;
        }
        else cur=cur*10+(input[i]-'0');
    }
}

int main(){
    int n;
    cin>>n;
    while(n>0){
        string command;//명령어어
        cin >> command;
        int num;
        cin >> num;
        deque<int> dq;
        parser(num,dq);//dq에 배열넣음
        
        int flag=1;//원래방향
        int errorflag=0;
        for(int i=0;i<command.length();i++){//처리
            if(command[i]=='R') flag*=-1;
            else{//D
                if(dq.empty()){
                    errorflag=1;
                    break;
                }
                else{
                    if(flag==1){
                        dq.pop_front();
                    }
                    else dq.pop_back();
                }

            }
        }
       // printf("errorflag%d",errorflag);
        if(errorflag==0){//출력
            if(dq.empty()) {
                cout<<"[]"<<'\n';
            }
            else{
                if(flag==1){
                    cout<<'['<<dq.front(); 
                    dq.pop_front();
                    while(!dq.empty()){
                        cout<<','<<dq.front();
                        dq.pop_front();
                    }
                    cout<<']'<<'\n';
                }
                else{
                    cout<<'['<<dq.back(); 
                    dq.pop_back();
                    while(!dq.empty()){
                        cout<<','<<dq.back();
                        dq.pop_back();
                    }
                    cout<<']'<<'\n';
                }
            }
        }
        else  cout<<"error"<<'\n';
        
        n--;
    }
    return 0;
}