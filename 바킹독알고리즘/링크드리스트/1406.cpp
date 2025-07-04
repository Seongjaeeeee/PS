#include<bits/stdc++.h>
using namespace std;
int main(){
    string a;
    cin >> a;
    list<char> L;
    for(int i=0; i<a.length();i++){
        L.push_back(a[i]);
    }
    list<char>::iterator t = L.end();//리스트의 끝임

    int num;
    cin >> num;
    for(int i=0;i<num;i++){
        char command;
        cin >> command;
        if(command == 'P'){
            char k;
            cin >> k;
            L.insert(t,k);
        }
        else if (command == 'B'){
            if(t != L.begin()) {
                t--;
                t = L.erase(t);//erase는 주의해야됨
            }
        }
        else if(command == 'L') {
            if(t != L.begin()) t--;
        }
        else if(command == 'D') {
            if(t != L.end())t++;
        }

    }

    for(auto i: L) cout<< i;
    
    return 0;
}