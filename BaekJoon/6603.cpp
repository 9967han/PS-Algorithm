#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
void input();
void DFS(int curNode, int curCnt, int num);
void printMap();
void initCheck();
int map[10000][14];
int check[10000][14];
int N;
vector<int> v;

int main() {
	input();
	// printMap();
	for(int i=1; i<=N; i++) {
		DFS(0, 0, i);
		printf("\n");
		initCheck();
		v.clear();
	}
}

void DFS(int curNode, int curCnt, int num){
	// printf("curNode : %d, curCnt : %d, num : %d\n", curNode, curCnt, num);
	if(curCnt == 6) {
		for(int i=1; i<=map[num][0]; i++) {
			if(check[num][i]) printf("%d ", map[num][i]);
		}
		printf("\n");
		return;
	}

	for(int i=curNode+1; i<=map[num][0]; i++) {
		if(check[num][i] == 0) {
			check[num][i] = 1;
			DFS(i, curCnt+1, num);
			check[num][i] = 0;
		}
	}
}

void input() {
	N = 1;
	while(true) {
		int k;
		scanf("%d", &k);
		if (k == 0) break;
		else {
			map[N][0] = k;
			for(int i=1; i<=k; i++) {
				scanf("%d", &map[N][i]);
			}
		}
		N++;
	}
}

void printMap() {
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=map[i][0]; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

void initCheck() {
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=map[i][0]; j++) {
			check[i][j] = 0;
		}
	}
}
