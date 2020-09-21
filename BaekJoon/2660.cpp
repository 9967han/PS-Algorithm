#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
void input();
void print();
void setScore();
void initFriends();
void findMaster();

int N;
int friends[51][51];
int result[51];

int main() {
	input();
	initFriends();
	setScore();
	findMaster();
}

void input() {
	scanf("%d", &N);
	int x=0, y=0;
	while(1) {
		scanf("%d %d", &x, &y);
		if (x == -1 && y == -1) break;
		friends[x][y] = 1;
		friends[y][x] = 1;
	}
}

void setScore() {
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			for(int k=1; k<=N; k++) {
				if(friends[j][k] > friends[j][i] + friends[i][k]) {
					friends[j][k] = friends[j][i] + friends[i][k];
				}
			}
		}
	}
}

void print() {
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			printf("%d ", friends[i][j]);
		}
		printf("\n");
	}
}

void initFriends() {
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			if (i == j) {
				friends[i][j] = 0;
			} else if (friends[i][j] != 1) {
				friends[i][j] = 100;
			}
		}
	}
}

void findMaster() {
	int masterScore=50;
	int personalScore=0;
	int masterNum=0;
	for(int i=1; i<=N; i++) {
		personalScore = 1;
		for(int j=1; j<=N; j++) {
			personalScore = max(friends[i][j], personalScore);
		}
		result[i] = personalScore;
		masterScore = min(masterScore, personalScore);
	}
	for(int i=1; i<=N; i++) {
		if(result[i] == masterScore) {
			masterNum++;
		}
	}
	printf("%d %d\n", masterScore, masterNum);
	for(int i=1; i<=N; i++) {
		if(result[i] == masterScore) {
			printf("%d ", i);
		}
	}
}
