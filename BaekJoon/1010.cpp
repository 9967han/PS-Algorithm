#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long dp[31][31];
int main(){
	int T, N, M;
	memset(dp, 0, sizeof(dp));
	cin >> T;
	for(int i=1; i<=30; i++) dp[1][i] = i;

	for(int i=2; i<=30; i++){
		dp[i][i] = 1;
		for(int j=i+1; j<=30; j++){
			for(int k=i-1; k<=j-1; k++){
				dp[i][j] += dp[i-1][k]; 
 			}
		}
	}

	for(int i=1; i<=T; i++){
		cin >> N >> M;
		cout << dp[N][M] << endl;
	}
	return 0;
}
