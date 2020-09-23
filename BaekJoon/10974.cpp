#include<stdio.h>
#include<algorithm>
using namespace std;
void DFS(int x, int cnt);

int N;
int arr[9];
int check[9];

int main(){
	scanf("%d", &N);

	DFS(1, 1);
}

void DFS(int x, int cnt){
	if(cnt == N+1) {
		for(int i=1; i<=N; i++){
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for(int i=1; i<=N; i++){
		if(!check[i]){
			arr[cnt] = i;
			check[i] = 1;
			DFS(i, cnt+1);
			check[i] = 0;
		}
	}
}