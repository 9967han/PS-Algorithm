#include<stdio.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
int cross[6];
int makeAllCase();
void input();
void makeCross(int a, int b, int c, int d, int arr[]);
int isCross(int a, int b, int c, int d);

int main(){
	input();
	int result = makeAllCase();
	printf("%d", result);
}
void input() {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);

	makeCross(a, b, c, d, cross);
}

void makeCross(int a, int b, int c, int d, int arr[]) {
	arr[1] = 1000*a + 100*b + 10*c + d;
	arr[2] = 1000*b + 100*c + 10*d + a;
	arr[3] = 1000*c + 100*d + 10*a + b;
	arr[4] = 1000*d + 100*a + 10*b + c;

	int minNum=arr[1];
	for(int i=1; i<=4; i++) {
		if(arr[i] < minNum) {
			minNum = arr[i];
		}
	}
	arr[5] = minNum;
	return ;
}

int isCross(int a, int b, int c, int d) {
	int cross2[6];
	makeCross(a, b, c, d, cross2);
	return cross2[5] == 1000*a+100*b+10*c+d;
}

int makeAllCase() {
	int a=0;
	for(int i=1; i<10; i++) {
		for(int j=1; j<10; j++) {
			for(int k=1; k<10; k++) {
				for(int l=1; l<10; l++) {
					if(isCross(i, j, k, l)) {
						if(cross[5] >= (i*1000 + j*100 + k*10 + l)) {
							a++;
						} else {
							return a;
						}
					}
				}
			}
		}
	}
	return a;
}