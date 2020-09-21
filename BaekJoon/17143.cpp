#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
void input();
void copyMap();
void printMap();
struct shark{
	int x; int y; int s; int d; int z;
};
shark moveShark(shark S);

int R, C, M;
int map[101][101], temp[101][101];
queue<shark> q, tempq;
int ans = 0;
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};

int main(){
	input();
	for(int curPos=1; curPos<=C; curPos++){
		// printMap();
		for(int j=1; j<=R; j++){
			if(map[j][curPos]){ // 상어가 있으면
				ans+=map[j][curPos]; // 잡음
				map[j][curPos] = 0;
				break;
			}
		}

		while(!q.empty()){ // C * M = C^3 
			shark curShark = q.front(); q.pop();
			if(map[curShark.x][curShark.y] == curShark.z) {
				tempq.push(moveShark(curShark)); // C^4  = 10^8 = 10000000
			}
		}

		while(!tempq.empty()){ // C^3
			shark curShark = tempq.front(); tempq.pop();
			if(curShark.z) q.push(curShark);
		}
		copyMap();
	}
	cout << ans;
}

void printMap(){
	cout << "cur ans : " << ans << endl;
	for(int i=1; i<=R; i++){
		for(int j=1; j<=C; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return;
}

void copyMap(){
	for(int i=1; i<=R; i++){
		for(int j=1; j<=C; j++){
			map[i][j] = temp[i][j];
		}
	}
	memset(temp, 0, sizeof(temp));
	return;
}

void input(){
	cin >> R >> C >> M;
	int r, c, s, d, z;
	for(int i=1; i<=M; i++){
		cin >> r >> c >> s >> d >> z;
		if(d == 1 || d == 2) s = s % (2*R - 2);
		else if(d == 3 || d == 4) s = s % (2*C - 2);
		map[r][c] = z;
		shark newShark = {r, c, s, d, z};
		q.push(newShark);
	}
}


shark moveShark(shark S){ // C^4
	shark newShark;
	int x, y, s, d, z;
	x = S.x; y = S.y; s = S.s; d = S.d; z = S.z;
	int nx = x, ny = y;
	for(int i=1; i<=s; i++){
		if(d == 3|| d == 4) {
			ny += dy[d];
			if(ny > C){
				ny = C-1;
				d = 4;
			} else if(ny < 1) {
				ny = 2;
				d = 3;
			}
		} else if(d == 1 || d == 2){
			nx += dx[d];
			if(nx > R) {
				nx = R-1;
				d = 1;
			} else if(nx < 1) {
				nx = 2;
				d = 2;
			}
		} 
	}

	if(temp[nx][ny] < z){
		temp[nx][ny] = z;
		newShark = {nx, ny, s, d, z};
		return newShark;
	}
	return newShark;
}