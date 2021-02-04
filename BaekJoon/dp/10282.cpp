#include<iostream>
#include<algorithm>
#include<cstring>
#define MOD 1000000007
using namespace std;
int dp[5002][5002];
int main(){
    memset(dp, 0, sizeof(dp));
    int T, N;
    cin >> T;
    dp[1][1] = 1;
    for(int i=2; i<=5000; i++){
        dp[i][0] += dp[i-1][1];
        for(int j=1; j<=i; j++){
            dp[i][j] += (dp[i-1][j+1] + dp[i-1][j-1]) % MOD;
        }
    }
    for(int t=1; t<=T; t++){
        cin >> N;
        cout << dp[N][0] << '\n';
    }
    return 0;
}