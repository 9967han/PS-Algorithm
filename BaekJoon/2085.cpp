#include<iostream>
#include<algorithm>
using namespace std;
int N, M, maxH=0, flag =0;
long long ans = 0;
int arr[1000001];
void findHeight(long long left, long long right);
int main(){
	cin >> N >> M;
	for(int i=1; i<=N; i++) {
		cin >> arr[i];
		maxH = max(maxH, arr[i]);
	}
	findHeight(1, maxH);
	cout << ans;
}

void findHeight(long long left, long long right){
	if(left > right) return;
	long long mid = (left + right)/2;	
	long long cnt = 0;
	for(int i=1; i<=N; i++) if(arr[i] >= mid) cnt += (arr[i] - mid);
	if(cnt >= M){
		ans = max(mid, ans);
		findHeight(mid+1, right);
	} else {
		findHeight(left, mid-1);
	}
	return;
}

