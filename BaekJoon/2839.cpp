#include<iostream>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int N, i, j;
	cin >> N;
	for(i=0; i<=1666; i++){
		for(j=0; j<=1000; j++){
			if(N == 3*i + 5*j) {
				cout << i+j;
				return 0;
			}
		}
	}
	cout << "-1";
}