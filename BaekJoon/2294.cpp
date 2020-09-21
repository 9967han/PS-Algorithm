#include<iostream>
#include<algorithm>
#include<set>
#include<queue>
#define INF 987654321
using namespace std;
queue<int> q;
set<int> s;
int main(){
    int N, K, x, ans = INF, dp[10001];
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        cin >> x;
        s.insert(x);
    }
    dp[0] = 0;
    for(int i=1; i<=K; i++) dp[i] = INF;
    q.push(0);

    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cur == K) {
            ans = min(ans, dp[cur]);
            continue;
        }
        for(int a : s) {
            if(cur+a > K || dp[cur+a] <= dp[cur]+1) continue;
            dp[cur+a] = min(dp[cur+a], dp[cur]+1); 
            q.push(cur+a);
        }
    }
    if(ans == INF) cout << "-1";
    else cout << ans;
}
