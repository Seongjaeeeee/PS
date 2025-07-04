#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin >> a;
    for(int i=0;i<a;i++){
        string pw;
        cin >> pw;
        list<char> L ={};
        auto t = L.end();
        for(auto c : pw){
            if(c=='<'){
                if(t!=L.begin()) t--;
            }
            else if(c=='>'){
                if(t!=L.end()) t++;
            }
            else if(c=='-'){
                if(t!=L.begin()){
                    t--;
                    t = L.erase(t);
                }
            }
            else L.insert(t,c);
        }
        for(auto z: L) cout<< z;
        cout << '\n';
    }
    
    return 0;
}