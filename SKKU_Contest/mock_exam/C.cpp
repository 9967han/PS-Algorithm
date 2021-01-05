#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int N, arr[1001];
set<int> s;
int main(){
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    set<int>::iterator iter;
    int res = 0;
    for(iter=s.begin(); iter!=s.end(); iter++){
        int cnt = 0, before = -1;
        for(int i=1; i<=N; i++){
            if(arr[i] == *iter) continue;
            if(before == -1) {
                before = arr[i];
                cnt++;
                continue;
            } 
            if(before != arr[i]) {
                cnt = 1;
                before = arr[i];
            } else {
                cnt++;
            }
            res = max(res, cnt);
        }
    }
    cout << res;
}