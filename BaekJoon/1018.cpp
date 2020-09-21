#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
void input();
void print();
int compare(int x, int y);
int N, M;
string map[50];
string white[] = 
{
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};
string black[] = 
{
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

int main() {
	input();
	int minans = 987654321;
	for(int i=0; i<=N-8; i++) {
		for(int j=0; j<=M-8; j++) {
			minans = min(minans, compare(i, j));
			// printf("minans : %d\n", minans);
		}
	}
	printf("%d", minans);
}

void input() {
	cin >> N >> M;
	for(int i=0; i<N; i++) {
		cin >> map[i];
	}
}

int compare(int x, int y) {
	int resultW = 0, resultB = 0;
	for(int i=x; i<x+8; i++) {
		for(int j=y; j<y+8; j++) {
			if(map[i][j] != white[i-x][j-y]) resultW++;
		}
	}
	for(int i=x; i<x+8; i++) {
		for(int j=y; j<y+8; j++) {
			if(map[i][j] != black[i-x][j-y]) resultB++;
		}
	}
	// printf("x : %d, y : %d, resultW : %d, resultB : %d\n", x, y, resultW, resultB);
	return min(resultW, resultB);
}

void print() {
	for(int i=0; i<N; i++) {
		cout << map[i] << '\n';
	}
}