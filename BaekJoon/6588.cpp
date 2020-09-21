#include<iostream>
#include<algorithm>
using namespace std;
#define SIZE 1000000
int map[1000002];
int check[1000002];
void getResult(int n);

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int N, maxN=0, len=0;
	for(len=1;; len++){
		cin >> map[len];
		if(map[len] == 0) break;
	}

	for (int i=2; i*i<SIZE; i++) {
		if (!check[i]){
			for (int j=i*i; j<SIZE; j+=i){
				check[j] = 1;
			}
		}
	}
	check[1] = 1;

	for(int i=1; i<=len; i++){
		int x = map[i];
		getResult(x);
	}
}

void getResult(int n) {
	if(n == 0) return;
	int i, j;
	int mid = n / 2;
	for (i = 0, j = n; i <= mid; i++, j--)
		if (i % 2 == 1 && j % 2 == 1 && !check[i] && !check[j]) {
			cout << n << " = " << i << " + " << j << "\n";
			return;
		}
	cout << "Goldbach's conjecture is wrong.\n";
}