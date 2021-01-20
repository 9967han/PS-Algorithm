#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, x;
vector<int> v;
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> x;
        if(i == 0) {
            v.push_back(x);
            continue;
        }
        if(v.back() < x) v.push_back(x);
        else {
            vector<int>::iterator iter;
            iter = lower_bound(v.begin(), v.end(), x);
            *iter = x;
        }
    }
    cout << v.size();
    return 0;
}