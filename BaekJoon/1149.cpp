#include<stdio.h>
#include<algorithm>
using namespace std;
int N;
int dp[1001][3];
int s[1001][3];
void input();

int main() {
	input();
	dp[1][0] = s[1][0];
	dp[1][1] = s[1][1];
	dp[1][2] = s[1][2];
	for(int i=2; i<=N; i++) {
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + s[i][0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + s[i][1];
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + s[i][2];
	}
	int result = min(min(dp[N][0], dp[N][1]), dp[N][2]);
	printf("%d", result);
}

void input() {
	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		scanf("%d %d %d", &s[i][0], &s[i][1], &s[i][2]);
	}
}