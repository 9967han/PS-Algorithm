#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define INF 987654321
int isPallen(int st, int en);
int dp[2501][2501];
int cnt[2501]; //0부터 N까지 팔린드롬 최소분할갯수
char str[2501]; // ABA CABA

int main(){
	scanf("%s", str);
 	int len = strlen(str);
 	memset(dp, -1, sizeof(dp));

 	for(int i=0; i<len; i++){
 		dp[i][i] = 1;
 		if(str[i] == str[i+1]) dp[i][i+1] = 1;
 	}


 	for(int i=0; i<len; i++){
 		for(int j=i; j<len; j++){
 			isPallen(i, j);
 		}
 	}

 	cnt[0] = 1;
 	for(int i=0; i<len; i++){
 		cnt[i] = INF;
 		for(int j=0; j<=i; j++){
 			if(isPallen(j,i)){
 				if(j-1 < 0) cnt[i] = 1;
 				else cnt[i] = min(cnt[i], cnt[j-1]+1);
 			}
 		}
 	}

 	printf("%d", cnt[len-1]);
}

int isPallen(int st, int en){
	if(st > en) return 1;

	int &result = dp[st][en];
	
	if (result != -1) return result;
	
	dp[st][en] = (str[st] == str[en]) && isPallen(st+1, en-1);
	return dp[st][en];
}