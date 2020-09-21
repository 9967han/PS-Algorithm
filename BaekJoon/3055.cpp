#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
void printMap();
int R, C;
int map[51][51];
int answer = 0;

struct hedge {
	int curx;
	int cury;
	int cnt;
};

queue<hedge> q;

int main(){
	cin >> R >> C;
	string str;
	for(int i=1; i<=R; i++){
		cin >> str;
		for(int j=1; j<=C; j++){
			if(str[j-1] == '.') map[i][j] = 0;
			else if(str[j-1] == 'D') map[i][j] = 99;
			else if(str[j-1] == 'X') map[i][j] = 3;
			else if(str[j-1] == '*') map[i][j] = 1;
			else if(str[j-1] == 'S') {
				map[i][j] = 2;
				hedge first;
				first.curx = i;
				first.cury = j;
				first.cnt = 0;
				q.push(first);
			}
		}
	}
	while(!q.empty()){
		hedge nowHedge = q.front(); q.pop();

	}

	printMap();
	return 0;
}

void printMap(){
	for(int i=1; i<=R; i++){
		for(int j=1; j<=C; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return ;
}
