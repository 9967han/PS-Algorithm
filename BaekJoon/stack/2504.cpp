#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;
string str;
stack<char> s;
int main(){
    cin >> str;
    long long res = 0, temp = 1;
    for(int i=0; i<str.size(); i++){
        if(str[i] == '('){
            s.push('(');
            temp *= 2;
        } else if(str[i] == '['){
            s.push('[');
            temp *= 3;
        } else if(str[i] == ')'){
            if(s.empty() || s.top() != '(') {
                cout << "0";
                return 0;
            }
            s.pop();
            if(str[i-1] == '(') res+=temp;
            temp /= 2;
        } else if(str[i] == ']'){
            if(s.empty() || s.top() != '[') {
                cout << "0";
                return 0;
            }
            s.pop();
            if(str[i-1] == '[') res+=temp;
            temp /= 3;
        } 
    }
    if(s.size()) cout << "0";
    else cout << res;
    return 0;
}