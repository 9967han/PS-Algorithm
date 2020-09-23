#include<iostream>
#include<algorithm>
using namespace std;
void input();
void print();
void bishop(int idx, int cnt, int color);
bool isDigo(int x, int y);

int N;
int res[] = {-1, -1};
int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, 1, 1, -1};
int map[11][11];
int colorMap[11][11];
bool Select[11][11];

int main(){
	input();

	bishop(0, 0, 0);
	bishop(0, 0, 1);

	cout << res[0] + res[1];
}

bool isDigo(int x, int y){
	for(int i=0; i<4; i++){
		int nx = x;
		int ny = y;

		while(true){
			if(nx < 0 || ny < 0 || nx >= N || ny >= N) break;
			if(Select[nx][ny] == true) return true;
			nx = nx + dx[i];
			ny = ny + dy[i];
		}
		
	}
	return false;
}



void bishop(int idx, int cnt, int color){
	res[color] = max(res[color], cnt);

	for(int i=idx; i<N*N; i++){
		int x = i/N;
		int y = i%N;

		if(colorMap[x][y] != color || map[x][y] == 0 || isDigo(x, y) == true) continue;
		Select[x][y] = true;
		bishop(i, cnt+1, color);
		Select[x][y] = false;
	}
	return;
}

void input(){
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> map[i][j];
			if((i+j)%2 == 0) colorMap[i][j] = 0;
			else colorMap[i][j] = 1;
		}
	}
	return;
}

void print(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << Select[i][j] << " ";
		}
		cout << endl;
	}
	return;
}