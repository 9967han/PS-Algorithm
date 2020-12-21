#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int N, x;
stack<int> s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    string str;
    for(int i=1; i<=N; i++){
        cin >> str;
        if(!str.compare("push")) {
            cin >> x;
            s.push(x);
        }else if(!str.compare("top")) {
            if(s.size()) cout << s.top() << '\n';
            else cout << "-1" << '\n';
        }else if(!str.compare("size")) {
            cout << s.size() << '\n';
        }else if(!str.compare("empty")) {
            if(s.empty()) cout << "1" << '\n';
            else cout << "0" << '\n';
        }else if(!str.compare("pop")) {
            if(s.size()) {
                cout << s.top() << '\n';
                s.pop();
            } else cout << "-1" << '\n';
        }
    }
    return 0;
}