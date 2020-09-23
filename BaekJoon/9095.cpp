#include<iostream>
using namespace std;
void input();
int T, N;
int dp[12];

int main(){
	cin >> T;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4; 
	for(int i=4; i<=11; i++){
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}

	for(int i=1; i<=T; i++){
		cin >> N;
		cout << dp[N] << endl;
	}
}