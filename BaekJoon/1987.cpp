#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
void print();
void DFS(int x, int y, int cnt);
void input();
int map[21][21];
int R, C;
int check[27];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int ret = 0;

int main(){ //A~Z : 1~26;
	input();
	check[map[1][1]] = 1;
	DFS(1, 1, 1);
	cout << ret;
}

void DFS(int x, int y, int cnt){
	if(cnt > ret) {
		ret = max(ret, cnt);
	} 

	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 1 && ny >= 1 && nx <= R && ny <= C) {
			if(check[map[nx][ny]] == 0) {
				check[map[nx][ny]] = 1;
				DFS(nx, ny, cnt + 1);
				check[map[nx][ny]] = 0;
			}	
		}
	}
}

void input(){
	cin >> R >> C;
	string s;
	for(int i=1; i<=R; i++){
		cin >> s;
		for(int j=1; j<=C; j++){
			if(s[j-1] != 0) map[i][j] = s[j-1]-64;
		}
	}
}

void print(){
	for(int i=1; i<=R; i++){
		for(int j=1; j<=C; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
