#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int dp[100001];
int main(){
    int N;
    cin >> N;
    for(int i=1; i<=sqrt(N); i++) dp[i*i] = 1;
    for(int i=2; i<=N; i++){
        if(dp[i] == 1) continue;
        dp[i] = 999;
        for(int j=1; j<=sqrt(i); j++){
            if(dp[j*j] == 1) dp[i] = min(dp[i], 1+dp[i-j*j]);
        }
    }
    cout << dp[N];
}
