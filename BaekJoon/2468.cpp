#include<iostream>
#include<algorithm>
using namespace std;
void input();
void print();
void initMap();
void soakRain(int x);
void DFS(int x, int y);

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
int N, minNum=987654321, maxNum=0, cnt=0, res=0;
int map[101][101];
int temp[101][101];
int check[101][101];

int main(){
	input();

	for(int k=minNum-1; k<=maxNum; k++){
		initMap();
		soakRain(k);

		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				if(!check[i][j] && map[i][j]) {
					cnt++;	
					DFS(i, j);
				}
			}
		}
		res = max(res, cnt);
	}

	cout << res;
}

void DFS(int x, int y){
	if(check[x][y] || map[x][y] == 0) return;
	check[x][y] = 1;
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 1 && ny >= 1 && nx <= N && ny <= N){
			if(map[nx][ny] == 1 && check[nx][ny] == 0) DFS(nx, ny);
		}
	}
}


void input(){
	cin >> N;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin >> map[i][j];
			temp[i][j] = map[i][j];
			maxNum = max(map[i][j], maxNum);
			minNum = min(map[i][j], minNum);
		}
	}
}

void print(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void soakRain(int x){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(map[i][j] <= x) map[i][j] = 0;
			else map[i][j] = 1;
		}
	}
}

void initMap(){
	cnt = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			map[i][j] = temp[i][j];
			check[i][j] = 0;
		}
	}
}