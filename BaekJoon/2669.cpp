#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
void input();
void printMap();
int rec[5][5];
int map[102][102];
int map2[102][102];
void addRec(int num, int x, int x2, int y, int y2);

int main() {
	input();
	for(int i=1; i<=4; i++) {
		addRec(i, rec[i][1], rec[i][3], rec[i][2], rec[i][4]);
	}
	printMap();
}

void input(){
	for(int i=1; i<5; i++) {
		for(int j=1; j<5; j++) {
			scanf("%d", &rec[i][j]);
		}
	}
}

void addRec(int num, int x, int x2, int y, int y2) {
	for(int i=x; i<x2; i++) {
		for(int j=y; j<y2; j++) {
			map[i][j]++;
		}
	}
}

void printMap() {
	int result=0;
	for(int i=1; i<101; i++) {
		for(int j=1; j<101; j++) {
			if(map[i][j] >= 1) {
				result++;
			}
		}
	}
	printf("%d", result);
} 