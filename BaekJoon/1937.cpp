#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
void input();
int DFS(int x, int y);

int dp[501][501];
int map[501][501];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int N;

int main(){
	input();

	int ans = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			ans = max(ans, DFS(i, j));
		}
	}
	cout << ans;
}

int DFS(int x, int y){
	if (dp[x][y]) return dp[x][y];
	dp[x][y] = 1;

	for(int k=0; k<=3; k++){
		int nx = x+dx[k];
		int ny = y+dy[k];
		if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
		if(map[nx][ny] > map[x][y]){
			dp[x][y] = max(dp[x][y], DFS(nx, ny) + 1);
		}
	}

	return dp[x][y];
}

void input(){
	cin >> N;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin >> map[i][j];
		}
	}
}

