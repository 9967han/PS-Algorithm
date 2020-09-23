#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
void input();

int N;
vector<pair<int,int> > v[26];

int main() {
	input();
}

void input() {
	int a, b, c, d;
	scanf("%d", &N);
	for(int i=1; i<=N/2; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		v[i].push_back(make_pair(a, b));
		v[i].push_back(make_pair(c, d));
	}
}

