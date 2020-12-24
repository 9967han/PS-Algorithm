#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int N, x, mid;
priority_queue<int> smallq, largeq;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> x;
        if(smallq.empty()) {
            smallq.push(x);
            mid = x;
            cout << smallq.top() << '\n';
            continue;
        } 
        if(mid < x) largeq.push(-x);
        else smallq.push(x);

        if(smallq.size() + 2 == largeq.size()){
            smallq.push(-largeq.top());
            largeq.pop();
        } else if(smallq.size() == largeq.size()+2){
            largeq.push(-smallq.top());
            smallq.pop();
        }

        if(smallq.size()+1 == largeq.size()) {
            mid = -largeq.top();
        } else {
            mid = smallq.top();
        }
        cout << mid << '\n';
    }
}