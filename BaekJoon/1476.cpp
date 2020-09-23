#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int E, S, M;
	cin >> E >> S >> M;
	int a=0, b=0, c=0;
	for(int i=1; ;i++){
		a++;
		b++;
		c++;
		if(a %16 == 0) a = 1;
		if(b %29 == 0) b = 1;
		if(c %20 == 0) c = 1;
		if(a == E && b == S && c == M){
			cout << i;
			break;
		}
	}
	return 0;
}