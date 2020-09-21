#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
void input();
void BFS(int i, int j);
void init();

int N, curCnt=0;
int map[101][101];
int check[101][101];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
queue<pair<int ,int> > q;

int main(){
	input();
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			BFS(i, j);
		}
	}
	cout << curCnt << " ";
	init();
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			BFS(i, j);
		}
	}
	cout << curCnt << endl;
}

void input(){
	cin >> N;
	string s;
	for(int i=1; i<=N; i++){
		cin >> s;
		for(int j=0; j<N; j++){
			if(s[j] == 'R') map[i][j+1] = 0;
			if(s[j] == 'G') map[i][j+1] = 1;
			if(s[j] == 'B') map[i][j+1] = 2;
		}
	}
}

void BFS(int a, int b){
	if(check[a][b]) return;
	curCnt++;
	check[a][b] = 1;
	q.push(make_pair(a, b));
	while(q.size() != 0){
		int x = q.front().first;
		int y = q.front().second;
		for(int i=0; i<4; i++){
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if(nx >= 1 && ny >= 1 && nx <= N && ny <= N && check[nx][ny] == 0) {
				if(map[x][y] == map[nx][ny]){
					check[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
		q.pop();
	}
}

void init(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			check[i][j] = 0;
			if(map[i][j] == 1) map[i][j] = 0;
		}
	}
	curCnt = 0;
}