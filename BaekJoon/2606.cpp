#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
void input();
void findSafe();
void findLink();
void checkMap();

int N, M;
queue<int> q;
std::vector<pair<int,int> > link;
std::pair <int, int> computer;
int result=0;
int check[101];

int main() {
	input();
	findSafe();
}

void input(){
	int x, y;
	scanf("%d", &N);
	scanf("%d", &M);
	for(int i=0; i<M; i++) {
		scanf("%d %d", &x, &y);
		link.push_back(make_pair(x, y));
	}
	for(int i=1; i<=N; i++) {
		check[i] = 0;
	}
	q.push(1);
	check[1] = 1;
}

void findLink(int start) {
	for(int i=0; i<link.size(); i++) {
		computer = link[i];
		if (computer.first == start && check[computer.second] == 0) {
			q.push(computer.second);
			check[computer.second] = 1;
		} else if(computer.second == start && check[computer.first] == 0) {
			q.push(computer.first);
			check[computer.first] = 1;
		}
	}
}

void findSafe(){
	while(q.size() != 0) {
		int start = q.front();
		findLink(start);
		q.pop();
	}
	checkMap();
}

void checkMap(){
	int a=0;
	for(int i=2; i<=100; i++) {
		if(check[i] == 1) {
			a++;
		}
	}
	printf("%d", a);
}