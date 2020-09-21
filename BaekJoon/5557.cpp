#include<stdio.h>
#include<algorithm>
using namespace std;
void input();
int N;
int map[101]={0};
long dp[101][21]={0};

int main(){
	input();
	dp[1][map[1]] = 1;
	for(int i=2; i<=N-1; i++) {
		for(int j=0; j<=20; j++) {
			if(dp[i-1][j] > 0) {
				if(j+map[i] <= 20) dp[i][j+map[i]] += dp[i-1][j];
				if(j-map[i] >= 0) dp[i][j-map[i]] += dp[i-1][j];
			} 
		}
	}
	printf("%ld", dp[N-1][map[N]]);
}

void input(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		scanf("%d", &map[i]);
	}
}