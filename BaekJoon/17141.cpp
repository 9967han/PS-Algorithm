#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#define INF 987654321
using namespace std;
void input();
void DFS(int idx, int cnt);
int diffuse();
void copyMap();
bool isFinished();
bool isFirstFinished();
void showMap();
struct virus{
	int x; int y; int level;
};
int N, M, ans=987654321;
int map[51][51], visit[51][51], temp[51][51];
int check[11];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
vector<pair<int, int> > v;
queue<virus> q;

int main(){
	input();
	if(isFirstFinished()){
		if(v.size() <= M) {
			cout << "0";
			return 0;
		}
	}
	
	DFS(1, 0);
	if(ans == INF) cout << "-1";
	else cout << ans;
	return 0;
}

void input(){
	cin >> N >> M;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin >> temp[i][j];
			if(temp[i][j] == 2) v.push_back(make_pair(i, j));
		}
	}
	return;
}

void DFS(int idx, int cnt){
	if(cnt == M){
		ans = min(ans, diffuse());
		return;
	}

	for(int i=idx; i<=v.size(); i++){
		if(check[i]) continue;
		check[i] = 1;
		DFS(i, cnt+1);
		check[i] = 0;
	}
	return;
}

int diffuse(){
	copyMap();
	int res = 1;
	for(int i=0; i<v.size(); i++){
		if(check[i+1]) q.push({v[i].first, v[i].second, 1});
		else map[v[i].first][v[i].second] = 0;
	}

	while(!q.empty()){
		virus cur = q.front(); q.pop();
		if(cur.level > res) {
			if(isFinished()) {
				while(!q.empty()) q.pop();
				return res;
			}
			else res++;
		}
		visit[cur.x][cur.y] = 1;
		map[cur.x][cur.y] = 99;

		for(int i=0; i<4; i++){
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if(nx < 1 || ny < 1 || nx > N || ny > N || visit[nx][ny] || map[nx][ny] == 1) continue;
			visit[nx][ny] = 1;
			map[nx][ny] = 99;
			virus newVirus = {nx, ny, cur.level+1};
			q.push(newVirus);
		}
	}
	return INF;
}

void copyMap(){
	memset(visit, 0, sizeof(visit));
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			map[i][j] = temp[i][j];
		}
	}
	return;
}

bool isFinished(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(!map[i][j]) return false;
		}
	}
	return true;
}

bool isFirstFinished(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(!temp[i][j]) return false;
		}
	}
	return true;
}

void showMap(){
	cout << endl;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return;
}

