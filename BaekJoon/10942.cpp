#include<stdio.h>
#include<algorithm>
using namespace std;
int isPallen(int st, int en);
int arr[2002];
int dp[2002][2002];
int N, M;

int main(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &arr[i]);
	}

	//길이 1 & 2
	for(int i=1; i<=N; i++){
		dp[i][i] = 1;
		if(arr[i] == arr[i+1]) dp[i][i+1] = 1;
	}

	scanf("%d", &M);
	int st, en;
	for(int i=1; i<=M; i++){
		scanf("%d %d", &st, &en);
		printf("%d\n", isPallen(st, en));
	}
}


int isPallen(int st, int en){
	if(dp[st][en] == 1) return 1;
	dp[st][en] = (arr[st] == arr[en] && isPallen(st+1, en-1));
	return dp[st][en];
}