#include<iostream>
#include<algorithm>
using namespace std;
void getPartition(int n);
int map[10001];
int main(){
	int T, n;
	for(int i=2; i<=100; i++){
		for(int j=i+i; j<=10000; j+=i){
			map[j] = 1;
		}
	}
	map[2] = 0;
	cin >> T;
	for(int i=1; i<=T; i++){
		cin >> n;
		getPartition(n);
	}
}

void getPartition(int n){
	for(int i=n/2; i>=2; i--){
		if(!map[i] && !map[n-i]) {
			cout << i << " " << n-i << endl;
			break;
		}
	}
	return;
}