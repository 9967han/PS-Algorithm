#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
void input();
void DFS(int depth, int num);

int A[101], Oper[4];
int check[100];
int N, minans=987654321, maxans=-123456789;

int main(){
	input();
	DFS(1,A[0]);
	printf("%d\n%d", maxans, minans);
}

void input(){
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d %d %d %d", &Oper[0], &Oper[1], &Oper[2], &Oper[3]);
}


void DFS(int depth, int num){
	if(depth == N) {
		minans = min(minans, num);
		maxans = max(maxans, num);
		return;
	}
	for(int i=0; i<4; i++) {
		if(Oper[i]) {
			Oper[i]--;
			switch(i){
				case 0:
					DFS(depth+1, num + A[depth]);
					break;
				case 1:
					DFS(depth+1, num - A[depth]);
					break;
				case 2:
					DFS(depth+1, num * A[depth]);
					break;
				case 3:
					DFS(depth+1, num / A[depth]);
					break;
			}
			Oper[i]++;
		}
	}
}