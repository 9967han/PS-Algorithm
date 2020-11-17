#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;
stack<char> s;
int main(){
    string str;
    int t = 1;
    while(1){
        cin >> str;
        if(str[0] == '-') break;
        int num = 0;
        for(int i=0; i<str.size(); i++){
            if(str[i] == '{') s.push('{');
            else {
                if(s.size() && s.top() == '{') s.pop();
                else s.push('}');
            }
        }
        while(!s.empty()){
            char c = s.top();
            s.pop();
            if(s.top() == c) num++;
            else num+=2;
            s.pop();
        }
        cout << t << ". " << num << endl;
        t++;
    }
}