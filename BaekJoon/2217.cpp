#include<iostream>
#include<algorithm>
using namespace std;

int rope[100001];
int N;
int main(){
	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> rope[i];
	}
	sort(rope+1, rope+N+1, greater<int>());
	int res=rope[1];
	for(int i=2; i<=N; i++){
		res = max(res, rope[i]*i);
	}
	cout << res;
}