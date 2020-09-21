#include<iostream>
using namespace std;

int A, B, V;

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> A >> B >> V;
	if((V-A)%(A-B) == 0) cout << (V-A)/(A-B)+1;
	else cout << (V-A)/(A-B)+2;	
}
