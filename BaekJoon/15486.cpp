#include<iostream>
#include<algorithm>
using namespace std;

long long dp[1500002];
long long Ti[1500002], Pi[1500002];
int main(){
	int N;
	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> Ti[i] >> Pi[i];	
	}
	for(int i=1; i<=N+1; i++){
		dp[i+Ti[i]] = max(dp[i+Ti[i]], dp[i]+Pi[i]);
		dp[i+1] = max(dp[i+1], dp[i]);
	}
	cout << dp[N+1];
	return 0;
}
