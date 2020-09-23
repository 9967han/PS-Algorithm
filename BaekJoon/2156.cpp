#include<iostream>
#include<algorithm>
using namespace std;
int dp[10001][3];
int map[10001];

int main(){
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> map[i];
	} 
	
	if(n == 1) {
		cout << map[1];
		return 0;
	}

	dp[1][1] = map[1];
	dp[1][2] = map[1];
	dp[2][1] = map[2];
	dp[2][2] = map[1] + map[2];
	for(int i=3; i<=n; i++){
		dp[i][1] = dp[i-2][2] + map[i];
		dp[i][2] = dp[i-1][1] + map[i];
		// cout << dp[i][1] << " " << dp[i][2] << endl;
		cout << max(max(dp[i-1][1], dp[i-1][2]), max(dp[i][1], dp[i][2])) << endl;
	}

	int a = max(dp[n-1][1], dp[n-1][2]);
	int b = max(dp[n][1], dp[n][2]);
	cout << max(a, b);
}
