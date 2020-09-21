#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int map[1001][1001], dp[1001][1001];
int main(){
    int N, M;
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> map[i][j];
        }
    }
    memset(dp, 0, sizeof(dp));
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            dp[i][j] = map[i][j];
            dp[i][j] = max(dp[i][j], dp[i-1][j] + map[i][j]);
            dp[i][j] = max(dp[i][j], dp[i][j-1] + map[i][j]);
            dp[i][j] = max(dp[i][j], dp[i-1][j-1] + map[i][j]);
        }
    }
    cout << dp[N][M];
}
