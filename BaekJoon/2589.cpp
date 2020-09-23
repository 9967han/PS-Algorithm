#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
void input();
void printMap();
void BFS();
struct land{
	int x;
	int y;
	int dis;
};
int map[51][51], visit[51][51];
int N, M, ans=0;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
queue<land> q;
int main(){
	input();

	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			memset(visit, 0, sizeof(visit));
			if(!map[i][j] && !visit[i][j]) {
				visit[i][j] = 1;
				q.push({i, j, 0});
				BFS();
			}
		}
	}
	
	cout << ans;
	return 0;
}

void BFS(){
	while(!q.empty()){
		// printMap();
		land cur = q.front(); q.pop();
		ans = max(ans, cur.dis);
		for(int i=0; i<4; i++){
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			int ndis = cur.dis + 1;
			if(nx < 1 || ny < 1 || nx > N || ny > M || map[nx][ny] || visit[nx][ny]) continue;
			visit[nx][ny] = 1;
			q.push({nx, ny, ndis});
		}
	}
	return;
}

void input(){
	cin >> N >> M;
	string s;
	for(int i=1; i<=N; i++){
		cin >> s;
		for(int j=1; j<=M; j++){
			if(s[j-1] == 'L') map[i][j] = 0;
			else map[i][j] = 1;
		}
	}
	return;
}

void printMap(){
	cout << endl;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cout << visit[i][j] << " ";
		}
		cout << endl;
	}
}
