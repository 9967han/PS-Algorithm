#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
void input();
void printTomato();
void spread();
void printDate();
void findResult();

int M, N;
int tomato[1001][1001];
int date[1001][1001];
std::queue<pair<int,int> > ripeTomato;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

int main() {
	input();
	spread();
	findResult();
}

void input() {
	scanf("%d %d", &M, &N);
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			scanf("%d", &tomato[i][j]);
			if (tomato[i][j] == 1) {
				ripeTomato.push(make_pair(i, j));
				date[i][j] = 0;
			} else if(tomato[i][j] == 0) {
				date[i][j] = -1;
			} else if(tomato[i][j] == -1) {
				date[i][j] = -2;
			}
		}
	}
}

void spread() {
	std::pair <int, int> tomatoTemp;
	int nx, ny;
	while(ripeTomato.size() != 0) {
		tomatoTemp = ripeTomato.front();
		for(int i=0; i<4; i++) {
			nx = tomatoTemp.first + dx[i];
			ny = tomatoTemp.second + dy[i];
			if (tomato[nx][ny] == 0 && nx >= 1 && ny >= 1 && nx <= N && ny <= M) {
				if (date[nx][ny] != -2 && date[nx][ny] < date[tomatoTemp.first][tomatoTemp.second]) {
					date[nx][ny] = date[tomatoTemp.first][tomatoTemp.second]+1;
					tomato[nx][ny] = 1;
					ripeTomato.push(make_pair(nx, ny));
				}
			}
		}
		ripeTomato.pop();
	}
}


void printTomato() {
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			printf("%d", tomato[i][j]);
		}
		printf("\n");
	}
}

void printDate() {
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			printf("%d", date[i][j]);
		}
		printf("\n");
	}
}

void findResult() {
	int max = 0;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			if(date[i][j] == -1) {
				printf("-1");
				return;
			}
			if(date[i][j] > max) {
				max = date[i][j];
			}
		}
	}
	printf("%d", max);
}