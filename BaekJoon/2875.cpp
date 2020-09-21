#include<stdio.h>
#include<algorithm>
using namespace std;
int N, M, K;
int main(){
	scanf("%d %d %d", &N, &M, &K);
	while(K!=0) {
		if(N > 2*M && N>0) { // 0 10 5
			N--;
		} else {
			M--;
		}
		K--;
	}
	int result = min(N/2, M);
	printf("%d", result);
}