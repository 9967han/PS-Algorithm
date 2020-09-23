#include<iostream>
#include<algorithm>
using namespace std;
int dp[100001], dp2[100001];
int map[100001];
int N;

int main(){
	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> dp[i];
	}

	int res = dp[1];
	for(int i=2; i<=N; i++){
		dp[i] = max(dp[i] , dp[i-1] + dp[i]);
		res = max(res, dp[i]);
	}

	cout << res;
}
