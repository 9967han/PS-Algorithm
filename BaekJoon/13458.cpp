#include<stdio.h>
#include<algorithm>
void input();
int getMinNum(int a);
int N, B, C;
int A[1000001];

int main() {
	input();
	long long result = 0;
	int cnt=0;
	for(int i=1; i<=N; i++){
		result += getMinNum(i);
		// if (result >= 1000000) {
		// 	cnt++;
		// 	result -= 1000000;
		// }
	}
	printf("%lli", result);
}

void input() {
	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d", &A[i]);
	scanf("%d %d", &B, &C);
}

int getMinNum(int a) {
	int res=1;
	if(A[a]-B <= 0) {
		return 1;
	} else {
		if ((A[a]-B)%C == 0) {
			// printf("A[a]-B : %d, C : %d, A[a]-B/C : %d, A[a]-B/C+1 : %d\n", A[a]-B, C, (A[a]-B)/C, (A[a]-B)/C+1);
			return (A[a]-B)/C+1;
		} else {
			return (A[a]-B)/C+2;
		}
	}
}