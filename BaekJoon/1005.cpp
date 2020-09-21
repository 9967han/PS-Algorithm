#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
void initConn();
void input();
void find();
void ClearQueue(queue<int> &someQueue);
int T, N, K, W;
int D[1001], cnt[1001], ans[1001];
int conn[1001][1001];
queue<int> q;
int main(){
	input();
}

void input(){
	scanf("%d", &T);
	for(int i=1; i<=T; i++){
		initConn();
		scanf("%d %d", &N, &K);
		for(int j=1; j<=N; j++){
			scanf("%d", &D[j]);
			ans[j] = D[j];
		}
		for(int j=1; j<=K; j++){
			int st, en;
			scanf("%d %d", &st, &en);
			conn[st][en] = 1;
			cnt[en]++;
		}
		scanf("%d", &W);
		for(int j=1; j<=N; j++){
			if(cnt[j] == 0) {
				q.push(j);
			}
		}
		find();
		ClearQueue(q);
	}
	return;
}

void find(){
	while(!q.empty()){
		int now = q.front(); q.pop();
		if(now == W && cnt[now] == 0) {
			printf("%d\n", ans[now]);
			break;
		}
		for(int i=1; i<=N; i++) {
			if(conn[now][i]) {
				int next = i;
				cnt[next]--;
				ans[next] = max(ans[next], D[next] + ans[now]);
				if(cnt[next] == 0) {
					q.push(next);
				}
			}
		}
	}
}

void initConn(){
	for(int i=1; i<=N; i++){ 
		cnt[i] = 0;
		for(int j=1; j<=N; j++){
			conn[i][j] = 0;
		}
	}
	return;
}

void ClearQueue(queue<int> &someQueue){
	queue<int> empty;
	swap(someQueue, empty);
}
