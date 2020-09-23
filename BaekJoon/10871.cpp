#include<algorithm>
#include<iostream>
using namespace std;
int main(){
	int N, X, num;
	cin >> N >> X;
	for(int i=1; i<=N; i++){
		cin >> num;
		if(num < X) cout << num << " ";
	}
	return 0;
}
