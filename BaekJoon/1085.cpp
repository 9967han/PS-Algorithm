#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int x, y, w, h, minNum=1001;
	cin >> x >> y >> w >> h;
	minNum = min(minNum, x);
	minNum = min(minNum, y);
	minNum = min(minNum, w-x);
	minNum = min(minNum, h-y);
	cout << minNum;
	return 0;
}