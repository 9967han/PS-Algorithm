#include<stdio.h>
#include<algorithm>
#include<vector>
int N, M;
int map[9][9];

void input();

int main(){
	input();
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(map[i][j] != 0 || map[i][j] != 6) {
				
			}
		}
	}
	
}

void input(){
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			scanf("%d", &map[i][j]);
		}
	}
}