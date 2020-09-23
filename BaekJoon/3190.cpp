#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

void input();
void moveSnake();
void printMap();
void direction(int a);

int map[101][101];
int N, K, L;
int move_time[101];
int currentTime=0;
char move_direction[101]; 

queue<pair<int, int> > snake;    
int currentMoveDirectionX = 0;
int currentMoveDirectionY = 1;

int main() {
	input();
	// printMap();
	moveSnake();
	printf("%d", currentTime);
}

void input(){
	scanf("%d", &N);
	scanf("%d", &K);
	int appleX, appleY;
	for(int i=0; i<K; i++) {
		scanf("%d %d", &appleX, &appleY); //사과의 좌표
		map[appleX][appleY] = 1;
	}
	scanf("%d", &L);
	for(int i=0; i<L; i++) {
		scanf("%d %c", &move_time[i], &move_direction[i]);//이동 시간과 방향
	}
	map[1][1] = -1;
}


void printMap() {
	printf("\nCurrent Count : %d\n", currentTime);
	for(int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("-----end-------\n");
}

void moveSnake(){
	int nx, ny;
	snake.push(make_pair(1, 1));
	pair<int, int> tail;
	pair<int, int> head;
	while(1) {
		currentTime+=1;
		head = snake.back(); //머리확인
		nx = head.first + currentMoveDirectionX;
		ny = head.second + currentMoveDirectionY;
		// printf("currentMoveDirectionX : %d, currentMoveDirectionY : %d\n", currentMoveDirectionX, currentMoveDirectionY );
		if (nx > N || ny > N || nx < 1 || ny < 1) { // 벽만남 종료
			return;
		} else if (map[nx][ny] == -1) { // 뱀 몸통 만남 종료
			return;
		} else if (map[nx][ny] == 1) {// 사과 있음
			snake.push(make_pair(nx, ny)); 
			map[nx][ny] = -1;
		} else { //사과 없음
			snake.push(make_pair(nx, ny));
			map[nx][ny] = -1;
			tail = snake.front();
			// printf("tail_x : %d, tail_y : %d\n", tail.first, tail.second);
			map[tail.first][tail.second] = 0;
			snake.pop(); // 꼬리 이동
		}
		for(int a=0; a<L; a++) {
			if(move_time[a] == currentTime){
				direction(a);
			}
		}
		// printMap();
	}
}

void direction(int a) {
	if(move_direction[a] == 'D') {
		if(currentMoveDirectionX == 0 && currentMoveDirectionY == 1) {
			currentMoveDirectionX = 1;
			currentMoveDirectionY = 0;
		} else if(currentMoveDirectionX == 1 && currentMoveDirectionY == 0) {
			currentMoveDirectionX = 0;
			currentMoveDirectionY = -1;
		} else if(currentMoveDirectionX == 0 && currentMoveDirectionY == -1) {
			currentMoveDirectionX = -1;
			currentMoveDirectionY = 0; 
		} else if(currentMoveDirectionX == -1 && currentMoveDirectionY == 0) {
			currentMoveDirectionX = 0;
			currentMoveDirectionY = 1; 
		}
	}else if(move_direction[a] == 'L') {
		if(currentMoveDirectionX == 0 && currentMoveDirectionY == 1) {
			currentMoveDirectionX = -1;
			currentMoveDirectionY = 0;
		} else if(currentMoveDirectionX == -1 && currentMoveDirectionY == 0) {
			currentMoveDirectionX = 0;
			currentMoveDirectionY = -1;
		} else if(currentMoveDirectionX == 0 && currentMoveDirectionY == -1) {
			currentMoveDirectionX = 1;
			currentMoveDirectionY = 0; 
		} else if(currentMoveDirectionX == 1 && currentMoveDirectionY == 0) {
			currentMoveDirectionX = 0;
			currentMoveDirectionY = 1; 
		}
	}
}
