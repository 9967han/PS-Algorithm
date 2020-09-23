#include<stdio.h>
#include<iostream>
using namespace std;
int N, M;
int dp[301][301];

int main(){
	cin >> N >> M;
	dp[1][1] = 0;
	dp[1][2] = 1;
	dp[2][1] = 1;

	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if (i > 1) {
				if (i%2 == 0) dp[i][j] = dp[i/2][j]*2 + 1;
				else dp[i][j] = dp[i/2][j] + dp[i/2+1][j] + 1;
			}
			if (j > 1) {
				if (j%2 == 0) dp[i][j] = dp[i][j/2]*2 + 1;
				else dp[i][j] = dp[i][j/2] + dp[i][j/2+1] + 1;
			}
		}
	}
	cout << dp[N][M];
}
