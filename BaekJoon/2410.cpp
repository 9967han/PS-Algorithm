#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define MOD 1000000000
using namespace std;
int dp[1000001];
int coin[21];
int main(){
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<20; i++){
        coin[i] = pow(2, i);
    }
    int N;
    cin >> N;
    dp[0] = 1;
    for(int i=0; i<20; i++){
        for(int j=1; j<=N; j++){
            if(j >= coin[i]) dp[j] = (dp[j] + dp[j-coin[i]]) % MOD ;
        }
    }
    cout << dp[N];

    return 0;
}