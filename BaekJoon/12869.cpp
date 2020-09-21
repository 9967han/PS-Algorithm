#include<iostream>
#include<algorithm>
using namespace std;
#define INF 987654321
int calc(int x, int y, int z);

int dp[61][61][61];
int scv[3], N;

int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> scv[i];
	}
	
	cout << calc(scv[0], scv[1], scv[2]);

}

int calc(int x, int y, int z){
	if(x == 0 && y == 0 && z == 0) return 0;
	int ret = dp[x][y][z];
	if(ret != 0) return ret;

	ret = INF;
	ret = min(ret, calc(max(0, x-9), max(0, y-3), max(0, z-1)) + 1);
	ret = min(ret, calc(max(0, x-9), max(0, y-1), max(0, z-3)) + 1);
	ret = min(ret, calc(max(0, x-3), max(0, y-9), max(0, z-1)) + 1);
	ret = min(ret, calc(max(0, x-3), max(0, y-1), max(0, z-9)) + 1);
	ret = min(ret, calc(max(0, x-1), max(0, y-3), max(0, z-9)) + 1);
	ret = min(ret, calc(max(0, x-1), max(0, y-9), max(0, z-3)) + 1);

	dp[x][y][z] = ret;
	return ret;
}