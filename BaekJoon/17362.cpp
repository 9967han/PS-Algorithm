#include<iostream>
using namespace std;
long long N;

int main(){
	cin >> N;
	int a = N%8;
	if(a == 1){
		cout << 1;
	} else if(a == 2 || a == 0) {
		cout << 2;
	} else if(a == 3 || a == 7) {
		cout << 3;
	} else if(a == 4 || a == 6) {
		cout << 4;
	} else if(a == 5) {
		cout << 5;
	}
}