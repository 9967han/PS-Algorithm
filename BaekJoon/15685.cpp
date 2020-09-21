#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
void makeDragonCurves();

int N;
int map[101][101];
int dragonCurves[4][1024];

int main(){
	makeDragonCurves();

	cin >> N;
	for(int i=1; i<=N; i++){
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		map[x][y] = 1;
		for(int i=0; i<pow(2, g); i++){
			if(dragonCurves[d][i] == 0) {
				x++;
			} else if(dragonCurves[d][i] == 1) {
				y--;
			} else if(dragonCurves[d][i] == 2) {
				x--;
			} else if(dragonCurves[d][i] == 3) {
				y++;
			}
			if(x >= 0 && y >= 0 && x <= 100 && y <= 100) map[x][y] = 1;
		}
	}

	int res=0;
	for(int i=0; i<=100; i++){
		for(int j=0; j<=100; j++){
			if(i+1 <= 100 && j+1 <= 100 && map[j][i] && map[j+1][i] && map[j][i+1] && map[j+1][i+1]) res++;
		}
	}
	cout << res;
	return 0;
}



void makeDragonCurves(){
	dragonCurves[0][0] = 0;
	dragonCurves[1][0] = 1;
	dragonCurves[2][0] = 2;
	dragonCurves[3][0] = 3;

	for(int i=0; i<4; i++){
		for(int j=1; j<11; j++){
			for(int k=pow(2, j-1), l=1; k<pow(2, j); k++, l=l+2){
				int next = (dragonCurves[i][k-l] + 2)%4 - 1;
				dragonCurves[i][k] = next >= 0 ? next : 3;
			}
		}
	}
}

