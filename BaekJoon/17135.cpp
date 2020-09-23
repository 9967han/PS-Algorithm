#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
int getMonsterNum(int archer[]);
int getDistance(int x, int y, int nx, int ny);
void DFS(int idx, int cnt);
void printMap();
void copyMap();
void input();
void moveMonster();
int map[17][16], killedMonster[16][16], tempMap[16][16];
int visit[16], archer[4];
int N, M, D, ans=0;
int main(){
	input();
	DFS(1, 1);
	cout << ans;
}

void DFS(int idx, int cnt){
	if(cnt == 4) {
		for(int i=1, k=1; i<=M; i++) {
			if(visit[i]) archer[k++] = i;
		}
		ans = max(ans, getMonsterNum(archer));
		return;
	}

	for(int i=idx; i<=M; i++){
		if(!visit[i]) {
			visit[i] = 1;
			DFS(i, cnt+1);
			visit[i] = 0;
		}
	}
	return;
}

int getMonsterNum(int archer[]){
	int score = 0;
	vector<pair<int, pair<int, int> > >v;
	copyMap();
	for(int turn=1; turn<=N; turn++){ // 한턴
		memset(killedMonster, 0, sizeof(killedMonster));
		for(int archerNum=1; archerNum<=3; archerNum++){
			for(int i=1; i<=N; i++){
				for(int j=1; j<=M; j++){
					if(!map[i][j]) continue;
					int dist = getDistance(i, j, N+1, archer[archerNum]);
					if(dist <= D) v.push_back(make_pair(dist, make_pair(j, i)));
				}
			}
			if(v.size() == 0) continue;
			else if(v.size() == 1) killedMonster[v[0].second.second][v[0].second.first]++;
			else {
				sort(v.begin(), v.end());
				killedMonster[v[0].second.second][v[0].second.first]++;
			}
			v.clear();
		}
		for(int i=1; i<=N; i++){
			for(int j=1; j<=M; j++){
				if(killedMonster[i][j]) {
					map[i][j] = 0;
					score++;
				}
			}
		}	
		moveMonster();
	}
	return score;
}

void moveMonster(){
	for(int j=0; j<=M; j++){
		for(int i=N; i>=2; i--){
			map[i][j] = map[i-1][j];
		}
		map[1][j] = 0;
	}
	return;
}

void copyMap(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			map[i][j] = tempMap[i][j];
		}
	}
	return;
}

int getDistance(int x, int y, int nx, int ny){
	return abs(x - nx) + abs(y - ny);
}

void input(){
	cin >> N >> M >> D;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cin >> tempMap[i][j];
		}
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
