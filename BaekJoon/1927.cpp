#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<int> pq;
int main(){
	int N, x;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &x);
		if(x == 0) {
			if(pq.size()) {
				printf("%d\n", -pq.top()); pq.pop();
			} else {
				printf("0\n");
			}
		} else {
			pq.push(-x);	
		}
	}
	return 0;
}