#include<iostream>
#include<algorithm>
#include<stack>
#include<cstring>
#include<vector>
#include<cmath>
#define ERR 1000000000
using namespace std;
void getOutput(long long x);
void input();
stack<long long> s;
vector<string> v;
bool flag = false;
int main(){
    while(1){
        input();
        long long N, x;
        cin >> N;
        for(int i=1; i<=N; i++){
            cin >> x;
            getOutput(x);
            if(flag || s.size() != 1) {
                cout << "ERROR\n";
            } else {
                cout << s.top() << '\n';
            }
            while(!s.empty()) s.pop();
        }
        cout << '\n';
        v.clear();
    }
    return 0;
}

void input(){
    string str;
    while(1){
        cin >> str;
        if(str.compare("QUIT") == 0) exit(0);
        v.push_back(str);
        if(str.compare("END") == 0){
            break;
        }
    }
    return;
}

void getOutput(long long x){
    s.push(x);
    long long first, second;
    flag = false;
    for(int i=0; i<v.size(); i++){
        string str = v[i];
        if(str.compare("NUM") == 0){
            s.push(stoi(v[i+1]));
        } else if(str.compare("POP") == 0){
            if(s.empty()) {
                flag = true;
                break;
            }
            s.pop();
        } else if(str.compare("INV") == 0){
            if(s.empty()) {
                flag = true;
                break;
            }
            first = s.top(); s.pop();
            s.push(first*(-1));
        } else if(str.compare("DUP") == 0){
            if(s.empty()) {
                flag = true;
                break;
            }
            first = s.top();
            s.push(first);
        } else if(str.compare("SWP") == 0){
            if(s.size() < 2) {
                flag = true;
                break;
            }
            first = s.top(); s.pop();
            second = s.top(); s.pop();
            s.push(first);
            s.push(second);
        } else if(str.compare("ADD") == 0){
            if(s.size() < 2) {
                flag = true;
                break;
            }
            first = s.top(); s.pop();
            second = s.top(); s.pop();
            if(abs(first + second) > ERR) {
                flag = true;
                break;
            }
            s.push(first + second);
        } else if(str.compare("SUB") == 0){
            if(s.size() < 2) {
                flag = true;
                break;
            }
            first = s.top(); s.pop();
            second = s.top(); s.pop();
            if(abs(second - first) > ERR) {
                flag = true;
                break;
            }
            s.push(second - first);
        } else if(str.compare("MUL") == 0){
            if(s.size() < 2) {
                flag = true;
                break;
            }
            first = s.top(); s.pop();
            second = s.top(); s.pop();
            if(abs(first * second) > ERR) {
                flag = true;
                break;
            }
            s.push(first * second);
        } else if(str.compare("DIV") == 0){
            if(s.size() < 2) {
                flag = true;
                break;
            }
            first = s.top(); s.pop();
            second = s.top(); s.pop();
            if(first == 0) {
                flag = true;
                break;
            }
            if(first > 0 && second > 0) {
                s.push(second / first);
            } else if(first < 0 && second < 0) {
                first = abs(first);
                second = abs(second);
                s.push(second / first);
            } else {
                first = abs(first);
                second = abs(second);
                s.push((second / first) * (-1));
            }
        } else if(str.compare("MOD") == 0){
            if(s.size() < 2) {
                flag = true;
                break;
            }
            first = s.top(); s.pop();
            second = s.top(); s.pop();
            if(first == 0) {
                flag = true;
                break;
            }
            if(first > 0 && second > 0) {
                s.push(second % first);
            } else if(second >= 0) {
                first = abs(first);
                s.push(second % first);
            } else if(second < 0) {
                first = abs(first);
                second = abs(second);
                s.push((second % first) * (-1));
            }
        } 
    }
    return;
}