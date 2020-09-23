#include<algorithm>
#include<iostream>
using namespace std;
void DFS(int x, int y);
void printMap();
void initMap();

int map[51][51];
int check[51][51];
int w, h;
int cnt = 0;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

int main(){
	while(1){
		initMap();
		cin >> w >> h;
		if(w == 0 && h == 0) break;

		for(int i=1; i<=h; i++){
			for(int j=1; j<=w; j++){
				cin >> map[i][j];
			}
		}

		for(int i=1; i<=h; i++){
			for(int j=1; j<=w; j++){
				if(!check[i][j] && map[i][j] == 1) {
					cnt++;
					DFS(i, j);
				}
			}
		}

		cout << cnt << endl;
	}
}

void DFS(int x, int y){
	if(map[x][y] == 0 || check[x][y] == 1) return;
	check[x][y] = 1;
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			int nx = x + dx[i];
			int ny = y + dy[j];
			if(nx >= 1 && ny >= 1 && nx <= h && ny <= w){
				if(map[nx][ny] == 1 && check[nx][ny] == 0) DFS(nx, ny);
			}
		}
	}

}

void printMap(){
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void initMap(){
	cnt = 0;
	for(int i=1; i<=50; i++){
		for(int j=1; j<=50; j++){
			map[i][j] = 0;
			check[i][j] = 0;
		}
	}
}