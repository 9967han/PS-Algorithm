#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 987654321
using namespace std;
int getMinNum(int left, int right);
int dp[501][501];
pair<int, int> arr[501];
int N;
int main(){
    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i].first >> arr[i].second;
    memset(dp, -1, sizeof(dp));
    cout << getMinNum(1, N);
    return 0;
}

int getMinNum(int left, int right){
    if(left == right) return 0;
    int &res = dp[left][right];
    if(res != -1) return res;

    res = INF;
    for(int i=left; i<=right; i++){
        res = min(res, getMinNum(left,i) + getMinNum(i+1, right) + arr[left].first*arr[i].second*arr[right].second);
    }
    return res;
}