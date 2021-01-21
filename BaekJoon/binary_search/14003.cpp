#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
int N, idx[1000001], arr[1000001];
vector<int> v;
stack<int> s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        if(i == 0) {
            v.push_back(arr[i]);
            idx[i] = v.size();
            continue;
        }
        if(v.back() < arr[i]) {
            v.push_back(arr[i]);
            idx[i] = v.size();
        }
        else {
            vector<int>::iterator iter;
            iter = lower_bound(v.begin(), v.end(), arr[i]);
            idx[i] = iter-v.begin()+1;
            *iter = arr[i];
        }
    }
    cout << v.size() << '\n';
    for(int i=N-1, cnt=v.size(); i>=0; i--){
        if(idx[i] == cnt) {
            s.push(arr[i]);
            cnt--;
        }
    }
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}