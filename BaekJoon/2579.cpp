#include<stdio.h>
#include<algorithm>
using namespace std;
void input();
int N;
int s[301];
int d[301][2];

int main() {
	input();
	d[1][0] = s[1];
	d[1][1] = 0;
	for(int i=2; i<=N; i++) {
		d[i][0] = max(d[i-2][0], d[i-2][1]) + s[i];
		d[i][1] = d[i-1][0] + s[i];
	}
	printf("%d", max(d[N][0], d[N][1]));

	return 0;
}

void input() {
	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		scanf("%d", &s[i]);
	}
	return;
}