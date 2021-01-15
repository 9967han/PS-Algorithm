#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int N, K;
int dp[101][100001]; // i번째일 때, 가질 수 있는 최대 value
int main(){
    memset(dp, 0, sizeof(dp));
    cin >> N >> K;
    int w, v, res=0;
    for(int i=1; i<=N; i++){
        cin >> w >> v;  
        for(int j=1; j<=K; j++){   
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if(j>=w) dp[i][j] = max(dp[i][j], dp[i-1][j-w] + v);
            res = max(res, dp[i][j]);
        }
    }
    cout << res;
    return 0;
}   