#include<iostream>
#include<algorithm>
using namespace std;
int N, arr[1001], dp[1001];
//dp[i] : i번째 원소까지 가장 긴 증가하는 부분수열 길이 (1~i-1 원소들 중, i번째 보다 작은 원소의 값이 있다면 그거dp + 1)
int main(){
	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> arr[i];
	}

	for(int i=1; i<=N; i++){
		dp[i] = 1;
		for(int j=1; j<i; j++){
			if(arr[j] < arr[i]){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int ans = 1;
	for(int i=1; i<=N; i++){
		ans = max(ans, dp[i]);
	}
	cout << ans;
}
