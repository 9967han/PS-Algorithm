#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int map[501][501];
int dp[501][501];
int main(){
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			cin >> map[i][j];
		}
	}

	dp[1][1] = map[1][1];
	for(int i=2; i<=n; i++){
		for(int j=1; j<=i; j++){
			if(j == 1) dp[i][1] = dp[i-1][1] + map[i][1];
			else if(j == i) dp[i][i] = dp[i-1][i-1] + map[i][i];
			else dp[i][j] = map[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
		}
	}


	int ans = 0;
	for(int i=1; i<=n; i++){
		ans = max(ans, dp[n][i]);
	}
	cout << ans;
}