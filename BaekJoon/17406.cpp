#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
void executeRotate(int r, int c, int s);
int decideRotates();
void DFS(int cnt);
void copyMap();
int getScore();
void input();
int map[51][51], tempMap[51][51];
int rcs[7][4];
int visit[7], turn[7];
int N, M, K, ans=987654321;
int main(){
	input();
	DFS(1);
	cout << ans;
}

void DFS(int cnt){
	if(cnt == K+1){
		ans = min(ans, decideRotates());
		return;
	}

	for(int i=1; i<=K; i++){
		if(!visit[i]){
			visit[i] = 1;
			turn[cnt] = i;
			DFS(cnt+1);
			visit[i] = 0;
		}
	}
}

int decideRotates(){
	copyMap();
	for(int i=1; i<=K; i++){
		executeRotate(rcs[turn[i]][1], rcs[turn[i]][2], rcs[turn[i]][3]);
	}
	return getScore();
}

int getScore(){
	int minScore = 987654321;
	for(int i=1; i<=N; i++){
		int score = 0;
		for(int j=1; j<=M; j++){
			score += map[i][j];
		}
		minScore = min(minScore, score);
	}
	return minScore;
}

void executeRotate(int r, int c, int s){
	int tempOne;
	for(int i=1; i<=s; i++){
		tempOne = map[r-i][c+i];
		for(int j=c+i; j>=c-i+1; j--) map[r-i][j] = map[r-i][j-1]; //위
		for(int j=r-i; j<=r+i-1; j++) map[j][c-i] = map[j+1][c-i]; // 왼쪽
		for(int j=c-i; j<=c+i-1; j++) map[r+i][j] = map[r+i][j+1]; // 아래
		for(int j=r+i; j>=r-i+1; j--) map[j][c+i] = map[j-1][c+i]; // 오른쪽
		map[r-i+1][c+i] = tempOne;
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

void input(){
	cin >> N >> M >> K;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cin >> tempMap[i][j];
		}
	}
	for(int i=1; i<=K; i++){
		cin >> rcs[i][1] >> rcs[i][2] >> rcs[i][3];
	}
}