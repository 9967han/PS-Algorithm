#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 987654321
using namespace std;
int DFS(int curNode, int curBit);

int N, W[16][16], cost[16][1 << 16];
int endBit;
int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> W[i][j];
		}
	}
	endBit = (1 << N) - 1;

	memset(cost, -1, sizeof(cost));
	cout << DFS(0, 1);
	return 0;
}

int DFS(int curNode, int curBit){
	if(curBit == endBit){
		if(W[curNode][0] == 0) return INF;
		else return W[curNode][0];
	}

	if(cost[curNode][curBit] != -1) return cost[curNode][curBit];
	cost[curNode][curBit] = INF;

	for(int i=0; i<N; i++){
		if(W[curNode][i] == 0) continue;
		if((curBit & (1 << i)) == (1 << i)) continue;

		cost[curNode][curBit] = min(cost[curNode][curBit], W[curNode][i] + DFS(i, curBit | 1 << i));
	}

	return cost[curNode][curBit];
}