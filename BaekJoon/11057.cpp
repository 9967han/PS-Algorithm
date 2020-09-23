#include<iostream>
#include<algorithm>
using namespace std;
int dp[1001][10];
int main(){
	int N;
	cin >> N;
	for(int i=0; i<10; i++) dp[1][i] = 1;
	for(int i=2; i<=1001; i++){
		for(int j=0; j<10; j++){
			for(int k=0; k<=j; k++){
				dp[i][j] += dp[i-1][k];
				dp[i][j] %= 10007;
			}
		}
	}
	long long sum = 0;
	for(int i=0; i<10; i++){
		sum += dp[N][i];
	}

	cout << sum % 10007;
}