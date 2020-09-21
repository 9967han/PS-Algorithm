#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
void input();
void print();
int N;
int map[501][501];
int check[501];
int ans[501];
queue<int> q;

int main() {
	input();
	for(int i=1; i<=N; i++) {
		if(check[i] == 0) {
			q.push(i);
			check[i] = -1;
		}
		ans[i] = map[i][0];
	}
	while(!q.empty()) {
		int a = q.front();
		q.pop();
		for(int i=1; i<=N; i++) {//1~N까지봐서 a를 가지면 시간더하기
			int j=1;
			while(map[i][j] != -1) {
				if(map[i][j] == a) {
					ans[i] = max(ans[i], ans[a] + map[i][0]);
					check[i]--;
				}
				j++;
			}
		}
		for(int i=1; i<=N; i++) {
			if(check[i] == 0 && check[i] != -1) {
				q.push(i);
				check[i] = -1;
			}
		}
	}
	for(int i=1; i<=N; i++) {
		printf("%d\n", ans[i]);
	}
}

void input(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		scanf("%d", &map[i][0]);
		int j=0;
		while(scanf("%d", &map[i][j+1]), map[i][j+1] != -1) j++;
		check[i] = j;
	}
}

void print() {
	for(int i=1; i<=N; i++) {
		int j=1;
		while(map[i][j] != -1) {
			printf("%d ", map[i][j]);
			j++;
		}
		printf("\n");
	}
	printf("---\n");
	for(int i=1; i<=N; i++) {
		printf("%d ", check[i]);
	}
}