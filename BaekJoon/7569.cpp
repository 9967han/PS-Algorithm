#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
void input();
int map[101][101][101], visit[101][101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int dz[] = {-1, 1};
int N, M, H, ans=0;
struct tomato {
	int x, y, z, lev;
};
queue<tomato> q;

int main(){
	input();
	while(!q.empty()){
		tomato cur = q.front(); q.pop();
		ans = max(ans, cur.lev);
		for(int j=0; j<4; j++){ // 앞뒤 왼오
			int nx = cur.x + dx[j];
			int ny = cur.y + dy[j];
			if(nx < 1 || ny < 1 || nx > N || ny > M || map[nx][ny][cur.z] == -1) continue;
			if(map[nx][ny][cur.z] == 0) {
				map[nx][ny][cur.z] = 1;
				q.push({nx, ny, cur.z, cur.lev+1});
			}
		}
		for(int j=0; j<2; j++){ // 위 아래
			int nz = cur.z + dz[j];
			if(nz < 1 || nz > H || map[cur.x][cur.y][nz] == -1) continue;
			if(map[cur.x][cur.y][nz] == 0) {
				map[cur.x][cur.y][nz] = 1;
				q.push({cur.x, cur.y, nz, cur.lev+1});
			}
		}
	}
	for(int h=1; h<=H; h++){
		for(int i=1; i<=N; i++){
			for(int j=1; j<=M; j++){
				if(map[i][j][h] == 0) {
					cout << "-1";
					return 0;
				}
			}
		}
	}
	cout << ans;
	return 0;
}

void input(){
	cin >> M >> N >> H;
	for(int h=1; h<=H; h++){
		for(int i=1; i<=N; i++){
			for(int j=1; j<=M; j++){
				cin >> map[i][j][h];
				if(map[i][j][h] == 1) q.push({i, j, h, 0}); 
			}
		}
	}
	return;
}