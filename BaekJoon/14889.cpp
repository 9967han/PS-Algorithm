#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
vector<int> start;
vector<int> link;
void input();
void DFS(int curNode, int curCnt);

int N;
int map[21][21];
int check[21];
int ans=987654321;

int main() {
	input();
	DFS(0, 0);
	printf("%d", ans);
}

void input() {
	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}

void DFS(int curNode, int curCnt){
	// printf("curNode : %d, curCnt : %d\n", curNode, curCnt);
	if (curCnt == N/2) {
		for(int i=1; i<=N; i++) {
			if(check[i]) start.push_back(i);
			else link.push_back(i);
		}
		int len = start.size();
		int startScore = 0;
		int linkScore = 0;
		for(int i=0; i<len; i++) {//1 2 3  4 5 6
			for(int j=i+1; j<len; j++) {
				startScore += map[start[i]][start[j]];
				startScore += map[start[j]][start[i]];
				linkScore += map[link[i]][link[j]];
				linkScore += map[link[j]][link[i]];
			}
		}
		start.clear();
		link.clear();
		// printf("start : %d, link : %d\n", startScore, linkScore);
		ans = min(ans, abs(startScore-linkScore));
		return;
	} 

	for(int i=curNode+1; i<=N; i++) {
		if(check[i] == 0) {
			check[i] = 1;
			DFS(i, curCnt+1);
			check[i] = 0;
		}
	}
}
