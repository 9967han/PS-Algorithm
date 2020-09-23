#include<iostream>
#include<algorithm>
using namespace std;
void input();
void DFS(int x, int y);
void initMap();
int checkMap();
int N, M;
int check[101][101];
int map[101][101];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int main(){
	int ans=1;
	input();
	while(1) {
		DFS(1, 1);
		initMap();
		if(checkMap()) {
			ans++;
			continue;
		} else {
			break;
		}
	}
	cout << ans;
}

void input(){
	cin >> N >> M;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cin >> map[i][j]; 
		}
	}
}

void DFS(int x, int y){
	if(check[x][y]) return;
	check[x][y] = 1;

	for(int i=0; i<4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];

		if(nx < 1 || nx > N || ny < 1 || ny > M) continue;

		if(map[nx][ny] == 0){
			map[nx][ny] = -1;
			DFS(nx, ny);
		} else if(map[nx][ny] != -1){
			map[nx][ny]++;
		}
	}
}

void initMap(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(map[i][j] == -1 || map[i][j] >= 3) map[i][j] = 0;
			else if(map[i][j] == 1 || map[i][j] == 2) map[i][j] = 1; 
			check[i][j] = 0;
		}
	}
}

int checkMap(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(map[i][j] != 0) return 1;
		}
	}
	return 0;
}