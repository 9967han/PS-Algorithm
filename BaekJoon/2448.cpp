#include<iostream>
using namespace std;
char map[3500][6500];
void solve(int n, int x, int y);

int main(){
	int N, i, j;
	cin >> N;

	for(i=1; i<=N; i++){
		for(j=1; j<=2*N; j++){
			map[i][j] = ' ';
		}
	}

	solve(N, N, 1);

	for(i=1; i<=N; i++){
		for(j=1; j<=2*N; j++){
			cout << map[i][j];
		}
		cout << endl;
	}
}

void solve(int n, int x, int y){
	if(n == 3) {
		map[y][x] = '*';
		map[y+1][x-1] = '*';
		map[y+1][x+1] = '*';
		map[y+2][x-2] = '*';
		map[y+2][x-1] = '*';
		map[y+2][x] = '*';
		map[y+2][x+1] = '*';
		map[y+2][x+2] = '*';
		return;
	}

	solve(n/2, x, y);
	solve(n/2, x-n/2, y+n/2);
	solve(n/2, x+n/2, y+n/2);
}