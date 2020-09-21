#include<iostream>
#include<algorithm>
using namespace std;
int arr[10001];
int main(){
	int N, M, cnt=0;
	cin >> N >> M;
	for(int i=1; i<=N; i++) cin >> arr[i];
	int st = 1, en = 1, sum = arr[1];
	while(1){
		if(en == N+1) break;
		if(M > sum){
			en++;
			sum += arr[en];
		} else if(M == sum) {
			cnt++;
			en++;
			sum += arr[en];
		}
		else {
			sum -= arr[st];
			st++;
		}
	}
	cout << cnt;
}

// 10 5
// 1 2 3 4 2 5 3 1 1 2