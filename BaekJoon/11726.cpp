#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int N;
int dp[1001];
int mod=10007;

int main() {
	scanf("%d", &N);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for(int i=3; i<=N; i++) {
		dp[i] = (dp[i-1] + dp[i-2])%mod;
	}
	printf("%d", dp[N]);
}
