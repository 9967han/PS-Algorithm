#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int N, arr[100001][2], idx[100001];
vector<int>::iterator iter;
vector<pair<int, int> > v;
vector<int> lis;
stack<int> s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i][0] >> arr[i][1];
        v.push_back(make_pair(arr[i][0], arr[i][1]));
    }
    sort(v.begin(), v.end());
    for(int i=0; i<N; i++){
        if(i == 0) {
            lis.push_back(v[i].second);
            idx[i] = 0;
            continue;
        }
        if(lis.back() < v[i].second){
            lis.push_back(v[i].second);
            idx[i] = lis.size()-1; 
        } else {
            iter = lower_bound(lis.begin(), lis.end(), v[i].second);
            idx[i] = iter-lis.begin();
            *iter = v[i].second;
        }
    }
    for(int i=N-1, cnt=lis.size()-1; i>=0; i--){
        if(cnt == idx[i]) cnt--; 
        else s.push(v[i].first);
    }
    cout << s.size() << '\n';
    while(!s.empty()){
        cout << s.top() << '\n';
        s.pop();
    }
}