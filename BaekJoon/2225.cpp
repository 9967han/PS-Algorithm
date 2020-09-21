#include<iostream>
#include<algorithm>
#define x 1000000000
using namespace std;
int dp[201][201];
int main(){
	int N, M;
	cin >> N >> M;

	for(int i=0; i<=200; i++){
		dp[i][1] = 1;
	}

	//dp[n][k] = dp[n][k-1] + dp[n-1][k-1] + dp[n-2][k-1] + dp[n-3][k-1] + ...
	for(int i=0; i<=N; i++){
		for(int j=2; j<=M; j++){
			for(int k=0; k<=i; k++){
				dp[i][j] = dp[i][j]%x + dp[i-k][j-1]%x;
			}
		}
	}

	cout << dp[N][M]%x;
}