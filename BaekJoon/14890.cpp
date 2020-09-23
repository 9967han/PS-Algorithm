#include<stdio.h>
#include<algorithm>
#include<vector>
void input();
void findPath();
int isPath(int path[]);

int N, L;
int map[101][101];

int main() {
	input();
	findPath();
}

void input() {
	scanf("%d %d", &N, &L);
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	return ;
}

void findPath() {
	int path[101], pathCount=0;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			path[j] = map[i][j];
		}
		// if(isPath(path)== 1) printf("i : %d \n", i);
		pathCount += isPath(path);
	}
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			path[j] = map[j][i];
		}
		// if(isPath(path)== 1) printf("22i : %d\n", i);
		pathCount += isPath(path);
	}
	printf("%d", pathCount);
	return ;
}

int isPath(int path[]) {
	int temp = path[1];
	int cnt=1;
	for(int i=2; i<=N; i++) {
		if(path[i] == temp) {//높이 같음 
			// printf("i : %d, temp : %d", i, temp);
			cnt++;
		} else if (path[i] == temp+1){//오르막 1 1 2 3 3 3
			if(cnt >= L) {
				cnt = 1;
			} else {
				return 0;
			}
		} else if (path[i] == temp-1) {//내리막 3 2 1
			for(int j=0; j<L; j++) {
				if (i+j <= N && path[i+j] == temp-1) {
					continue;
				} else {
					return 0;
				}
			}
			if(i+L <= N && path[i+L] >= path[i]+1) {//곧바로 벽
				return 0;
			}
			temp = path[i+L-1];
			i=i+L;
			cnt = 0;			
			i--; 
			continue;			
		} else {
			return 0;
		}
		temp = path[i];
	}
	return 1;
}