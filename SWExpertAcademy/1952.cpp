#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int cost[5], plan[13], dp[13];
int main(){ 
    int T;
    cin >> T;
    for(int t=1; t<=T; t++){
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=4; i++) cin >> cost[i];
        for(int i=1; i<=12; i++) cin >> plan[i];
        dp[1] = min(cost[1] * plan[1], cost[2]);
        for(int i=2; i<=12; i++){
            dp[i] = min(dp[i-1] + plan[i] * cost[1], dp[i-1] + cost[2]);
            if(i >= 3) dp[i] = min(dp[i], dp[i-3] + cost[3]);
            if(i == 12) dp[i] = min(dp[i], cost[4]);
        }
        cout << "#" << t << " " << dp[12] << endl;
    }

}