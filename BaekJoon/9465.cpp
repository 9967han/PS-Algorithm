#include<iostream>
#include<algorithm>
using namespace std;
void initDP(int x);
int arr[2][100001];
int dp[2][100001];
int N, T;
int main(){
	cin >> T;
	for(int i=1; i<=T; i++){
		cin >> N;
		for(int j=1; j<=N; j++){
			cin >> arr[0][j];
		}
		for(int j=1; j<=N; j++){
			cin >> arr[1][j];
		}

		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];
		for(int j=2; j<=N; j++){
			dp[0][j] = max(dp[1][j-1] + arr[0][j], dp[1][j-2] + arr[0][j]);
			dp[1][j] = max(dp[0][j-1] + arr[1][j], dp[0][j-2] + arr[1][j]);
		}

		cout << max(dp[0][N], dp[1][N]) << endl;
		initDP(N);
	}
}

void initDP(int x){
	for(int i=1; i<=x; i++){
		dp[0][i] = 0;
		dp[1][i] = 0;
	}
	return;
}