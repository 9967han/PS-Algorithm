#include<stdio.h>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
queue<long long> q;
int main(){
	int N, idx=-1;
	scanf("%d", &N);
	for(int i=0; i<=9; i++){
		q.push(i);
	}
	while(!q.empty()){
		idx++;
		long long now = q.front(); q.pop();
		if(idx == N) {
			printf("%lld", now);
			return 0;
		}
		if(now > 9876543210) break;
		int nowEnd = now%10;
		for(int i=0; i<nowEnd; i++){
			long long next = now*10 + i;
			q.push(next);
		}
	}
	printf("-1");
}	
