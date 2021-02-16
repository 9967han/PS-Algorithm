#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
stack<char> s, temp;
int main(){
    string st, en;
    cin >> st >> en;
    for(int i=0; i<en.size(); i++){
        s.push(en[i]);
    }
    while(s.size() != st.size()){
        char cur = s.top(); s.pop();
        if(cur == 'B'){
            while(!s.empty()) {
                temp.push(s.top());
                s.pop();
            }
            s = temp;
            while(!temp.empty()) {
                temp.pop();
            }
        }
    }

    int len = st.size()-1;
    while(!s.empty()){
        char cur = s.top(); s.pop();
        if (st[len] != cur){
            cout << "0";
            return 0;
        }
        len--;
    }
    cout << "1";
    return 0;
}