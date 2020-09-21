#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<set>
using namespace std;
void input();
void DFS(int startNode, int currentNode);
void printAnswer();
void initCheck();

int N;
int second[101];
int check[101];

vector<int> v;

int main() {
	input();
	for(int i=1; i<=N; i++) {
		DFS(i,i);
		initCheck();
	}
	printAnswer();
}

void input() {
	int x, max = 1;
	scanf("%d", &N);
	for(int i=1; i<=N; i++) {
		scanf("%d", &second[i]);
		check[i] = 0;
	}	
}

void DFS(int startNode, int currentNode) {
	if(check[currentNode] == 1) {
		if(startNode == currentNode) {
			v.push_back(startNode);
		}
	} else {
		check[currentNode] = 1;
		DFS(startNode, second[currentNode]);
	}
}

void initCheck() {
	for(int i=1; i<=N; i++) {
		check[i] = 0;
	}
}

void printAnswer(){
	int a = v.size();
	printf("%d\n", a);
	if (a == 0) {
		printf("0");
		return;
	}
	for(int i=0; i<a; i++){
		printf("%d\n", v[i]);
	}
}