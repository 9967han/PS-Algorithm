#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
void input();
void scan();
void printNum();
int findCase(int x, int y);

int map[11][11];
int num[11];
int num2[11];
vector<pair<int, int> > v[11];
char s[11];
vector<int> v1;
vector<int> v2;

int main() {
	input();
	scan();
	
}

void input(){
	for(int i=1; i<=10; i++) {
		num[i]=0;
		num2[i]=0;
		scanf("%s", s);
		for(int j=1; j<=10; j++) {
			map[i][j]=s[j-1]-48;
		}
	}
}

void scan(){
	for(int i=1; i<=10; i++) {
		for(int j=1; j<=10; j++) {
			if(map[i][j] == 1) {
				findCase(i, j);
				return;
			}
		}
	}
}

void printNum(){
	for(int i=1; i<=10; i++) {
		printf("%d ", num[i]);
	}
	printf("\n");
	for(int j=1; j<=10; j++) {
		printf("%d ", num2[j]);
	}
}

int findCase(int x, int y){
	//case 1



	//case2
	for(int i=x; i<=10; i++) {
		v1.push_back(num[i]);
		v2.push_back(num2[i]);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	if (v1.size() == v2.size()) {
		for(int i=0; i<v1.size(); i++) {
			if (v1[i] == v2[i]) {
				return 0;
			}
		}
		printf("triangle");
	}
}
