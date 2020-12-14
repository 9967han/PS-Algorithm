#include<iostream>
#include<algorithm>
using namespace std;
long long dp[92];
int main(){
    dp[1] = 0, dp[2] = 1, dp[3] = 1;
    for(int i=4; i<=91; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    int N;
    cin >> N;
    cout << dp[N+1];
}   