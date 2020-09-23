#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int N;
	int arr[1001], res[1001];
	cin >> N;
	for(int i=1; i<=N; i++) cin >> arr[i];
	sort(arr+1, arr+N+1);

	for(int i=1; i<=N; i++){
		int sum = 0;
		for(int j=1; j<=i; j++){
			sum += arr[j];
		}
		res[i] = sum;
	}

	int ans = 0;
	for(int i=1; i<=N; i++) {
		ans += res[i];
	}
	cout << ans;
}