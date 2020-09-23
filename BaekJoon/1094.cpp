#include<algorithm>
#include<iostream>
using namespace std;
int X, cnt = 0;
int main(){
	cin >> X;
	for(int i=0; i<=6; i++){
		if(X & (1 << i)) cnt ++;
	}
	cout << cnt;
}

