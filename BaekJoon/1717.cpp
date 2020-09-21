#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
void uni(int a, int b);
int find(int a);
int p[1000001], N, M;
int main(){
	scanf("%d %d", &N, &M);
	int cases, a, b;
	for(int i=1; i<=N; i++) p[i] = i;
	for(int i=0; i<M; i++){
		scanf("%d %d %d", &cases, &a, &b);
		if(cases == 0) uni(a, b);
		else {
			if(find(a) == find(b)) printf("YES\n");
			else printf("NO\n");
		}
	}
}

void uni(int a, int b) {
	int x = find(a);
	int y = find(b);
	if(x != y) p[y] = x;
	return;
}

int find(int a) {
	if(p[a] == a) return a;
	else return p[a] = find(p[a]);
}