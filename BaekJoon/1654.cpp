#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void input();
void changeResult(long long low, long long high);
int K, N;
int num[10001];
long long result=0;
int maxNum=0;

int main(){
	input();
	int high = maxNum;
	int low = 1;
	changeResult(low, high);
	cout << result;
}	

void input(){
	ios_base :: sync_with_stdio(false); 
	cin.tie(0); 

	cin >> K >> N;
	for(int i=1; i<=K; i++) {
		cin >> num[i];
		if(num[i] > maxNum) maxNum = num[i];
	}
	return;
}

void changeResult(long long low, long long high){
	// cout << low << " " << high << endl;
	if(low > high) return;
	long long mid = (low + high)/2;
	int cnt = 0;

	for(int i=1; i<=K; i++){
		cnt += (num[i] / mid);
		if(cnt >= N) break;
	}

	if (cnt >= N) {
		if(result < mid) result = mid;
		changeResult(mid+1, high);
	} else {
		changeResult(low, mid-1);
	}
	return ;
}