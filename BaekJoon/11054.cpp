#include<iostream>
#include<algorithm>
using namespace std;
int N, arr[1001];
int dp[1001], dp2[1001];
//dp[i] : i번째 원소까지 가장 긴 증가하는 부분수열 길이 (1~i-1 원소들 중, i번째 보다 작은 원소의 값이 있다면 그거dp + 1)
//dp2[i] : i번째 원소부터 N번째 원소까지 가장 긴 감소하는 부분수열 길이 (i~N 원소들 중, i번째 보다 작은 원소의 값이 있다면 그거dp2 + 1)
// 10
// 1 5 2 1 4 3 4 5 2 1
int main(){
	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> arr[i];
	}

	for(int i=1; i<=N; i++){
		dp[i] = 1;
		for(int j=1; j<i; j++){//1~i-1번째 중에
			if(arr[j] < arr[i]){//마지막 값이 i보다 작으면서
				dp[i] = max(dp[i], dp[j]+1);//i번째가 들어간 부분수열의 최대 길이 갱신
			}
		}
	}

	for(int i=N; i>=1; i--){
		dp2[i] = 1;
		for(int j=i; j<=N; j++){
			if(arr[j] < arr[i]){
				dp2[i] = max(dp2[i], dp2[j]+1);
			}
		}
	}

	int ans = 1;
	for(int i=1; i<=N; i++){
		ans = max(ans, dp[i]+dp2[i]-1);
	}
	cout << ans;
}
