#include<iostream>
#include<algorithm>
using namespace std;
int dp[1001];
int pi[1001];
int main(){
	int N;
	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> pi[i];
		dp[i] = pi[i];
	}
	for(int i=2; i<=N; i++){
		for(int j=1; j<=i; j++){
			dp[i] = max(dp[i], pi[j] + dp[i-j]);
		}
	}
	cout << dp[N];
}