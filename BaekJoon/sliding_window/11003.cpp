#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
int N, L, x;
deque<pair<int, int> > dq;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> L;
    for(int i=1; i<=N; i++){
        cin >> x;
        while(!dq.empty() && dq.back().first > x) dq.pop_back();
        int start = i-L+1;
        dq.push_back(make_pair(x, i));
        while(!dq.empty() && dq.front().second < start) dq.pop_front();
        cout << dq.front().first << " ";
    }
}