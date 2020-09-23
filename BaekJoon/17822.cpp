#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
void input();
void rotate(int idx);
void printMap();
void DFS(int x, int y);
int N, M, T, ans=0, caseCheck=0, cnt=0;
int map[51][51], visit[51][51], tempMap[51][51], rotArr[3][51], tempArr[51];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int main(){
	input();
	for(int i=1; i<=T; i++){
		rotate(i);
		// printMap();
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			ans += map[i][j];
		}
	}
	cout << ans;
}
	
void rotate(int idx){
	memset(visit, 0, sizeof(visit));
	memset(tempMap, 0, sizeof(tempMap));
	int xi = rotArr[0][idx], di = rotArr[1][idx], ki = rotArr[2][idx];
	for(int i=1; xi*i<=N; i++){// xi*i번째 원판들 회전
		int xn = xi*i;  
		if(di == 0) { // 시계방향 회전
			for(int j=1; j<=ki; j++){ // ki칸 회전
				tempArr[1] = map[xn][M];
				for(int k=2; k<=M; k++){
					tempArr[k] = map[xn][k-1];
				}
				for(int k=1; k<=M; k++){
					map[xn][k] = tempArr[k];
				}
			}
		} else if(di == 1) { // 반시계방향 회전
			for(int j=1; j<=ki; j++){ // ki칸 회전
				tempArr[M] = map[xn][1];
				for(int k=1; k<=M-1; k++){
					tempArr[k] = map[xn][k+1];
				}
				for(int k=1; k<=M; k++){
					map[xn][k] = tempArr[k];
				}
			}
		}
	}

	caseCheck = 0, cnt = 0;
	float mapTotal = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(map[i][j] && !visit[i][j]) { // 수가 남아 있으면
				cnt++;
				DFS(i, j); // 인접하면서 수가 같은 것을 찾는다.
			}
			mapTotal += map[i][j];
		}
	}

	if(caseCheck){ //수가 남아있으면
		for(int i=1; i<=N; i++){
			for(int j=1; j<=M; j++){
				if(tempMap[i][j]) map[i][j] = 0;
			}
		}
	}else{ //인접하면서 같은 수가 없는 경우
		mapTotal = mapTotal/cnt;
		for(int i=1; i<=N; i++){
			for(int j=1; j<=M; j++){
				if(map[i][j]) {
					if(map[i][j] < mapTotal) map[i][j]++;
					else if(map[i][j] > mapTotal) map[i][j]--;
				}
			}
		}
	}
}	

void DFS(int x, int y){
	if(visit[x][y]) return;
	visit[x][y] = 1;

	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(visit[nx][ny]) continue;
		if(nx < 1 || nx > N) continue;
		if(ny < 1) ny = M;
		if(ny > M) ny = 1;
		if(map[x][y] == map[nx][ny]){
			caseCheck = 1;
			tempMap[x][y] = 1;
			tempMap[nx][ny] = 1;
			DFS(nx, ny);
		}
	}
}

void input(){
	cin >> N >> M >> T;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cin >> map[i][j];
		}
	}
	for(int i=1; i<=T; i++){
		cin >> rotArr[0][i] >> rotArr[1][i] >> rotArr[2][i];
	}
	return;
}

void printMap(){
	cout << endl;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return;
}