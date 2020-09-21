#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
void input();
void DFS(int x, int y, int curState);

int N;
int map[17][17];
int curState = 0, cnt = 0; // 0: 오른쪽, 1 : 대각선, 2 : 아래

int main(){
	input();
	DFS(1, 2, 0);
	cout << cnt;
}

void input(){
	cin >> N;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin >> map[i][j];
		}
	}
}

void DFS(int x, int y, int curState){
	if(x == N && y == N) {
		cnt++;
		return;
	}
	if(x > N || y > N) {
		return;
	}
	if(curState == 0) {//가로
		if(map[x][y+1] == 0) {//가로 
			DFS(x, y+1, 0);
		}
		if(!(map[x+1][y] || map[x][y+1] || map[x+1][y+1])) {// 대각선가능
			DFS(x+1, y+1, 1);
		} 
	} else if(curState == 1) {//대각선
		if(map[x][y+1] == 0){//가로  
			DFS(x, y+1, 0);
		}
		if(!(map[x+1][y] || map[x][y+1] || map[x+1][y+1])) {// 대각선가능
			DFS(x+1, y+1, 1);
		} 
		if(map[x+1][y] == 0) {// 세로
			DFS(x+1, y, 2);
		} 
	} else {//세로
		if(map[x+1][y] == 0) {// 세로
			DFS(x+1, y, 2);
		}
		if(!(map[x+1][y] || map[x][y+1] || map[x+1][y+1])) {// 대각선가능
			DFS(x+1, y+1, 1);
		} 
	}
}