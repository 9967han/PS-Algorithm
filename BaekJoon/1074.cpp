#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
void searchMap(int n, int x, int y, int cnt);
int N, r, c;
int main(){
	cin >> N >> r >> c;
	searchMap(N, 0, 0, 0);
	return 0;
}

void searchMap(int n, int x, int y, int cnt){
	if(r  == x && y == c){
		cout << cnt;
		exit(0);
	} else {
		int stand = pow(2, n-1); 
		if(r < x+stand && c < y+stand) searchMap(n-1, x, y, cnt);
		if(r < x+stand && c >= y+stand) searchMap(n-1, x , y + stand, cnt + pow(stand, 2));
		if(r >= x+stand && c < y+stand) searchMap(n-1, x + stand, y, cnt + 2*pow(stand, 2));
		if(r >= x+stand && c >= y+stand) searchMap(n-1, x + stand, y + stand, cnt + 3*pow(stand, 2));
	}
	return;
}
