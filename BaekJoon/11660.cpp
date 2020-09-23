#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
int map[1025][1025], dp[1025][1025];
int main(){
    memset(dp, 0, sizeof(dp));
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%d", &map[i][j]);
        }
    }

    dp[1][1] = map[1][1];    
    for(int i=2; i<=N; i++){
        dp[i][1] = dp[i-1][1] + map[i][1];
        dp[1][i] = dp[1][i-1] + map[1][i];
    }

    for(int i=2; i<=N; i++){
        for(int j=2; j<=N; j++){
            dp[i][j] = (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + map[i][j]);
        }
    }

    int x1, x2, y1, y2;
    for(int i=1; i<=M; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1]);
    }
}