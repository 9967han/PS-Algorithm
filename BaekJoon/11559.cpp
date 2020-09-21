#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
void input();
void init();
void print();
void DFS(int x, int y);
int map[13][7];
int check[13][7];
int bombCnt = 0;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
vector<pair<int, int> > v;

int main(){
	input();
	// print();
	while(1){
		int flag = 0;
		for(int i=12; i>=1; i--){
			for(int j=6; j>=1; j--){
				if(map[i][j] >= 1) {
					DFS(i, j);
					if(v.size() >= 4) {
						flag = 1;
						for(int i=0; i<v.size(); i++){
							int x = v[i].first;
							int y = v[i].second;
							map[x][y] = 0;
						}
					}
					v.clear();
				}
			}
		}
		if(flag == 0) break;
		init();
		bombCnt++;
		// print();
	}
	cout << bombCnt << endl;
}

void input(){
	string s;
	for(int i=1; i<=12; i++){
		cin >> s;
		for(int j=0; j<=5; j++){
			if(s[j] == '.') map[i][j+1] = 0;
			else if(s[j] == 'R') map[i][j+1] = 1;
			else if(s[j] == 'Y') map[i][j+1] = 2;
			else if(s[j] == 'G') map[i][j+1] = 3;
			else if(s[j] == 'P') map[i][j+1] = 4;
			else if(s[j] == 'B') map[i][j+1] = 5;
		}
	}	
}

void DFS(int x, int y){
	if(check[x][y] == 1 || map[x][y] == 0) return;
	check[x][y] = 1;
	v.push_back(make_pair(x, y));
	for(int i=0; i<=3; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 13 || ny >= 13 || nx < 1 || ny < 1 || map[nx][ny] == 0) continue;
		if(map[nx][ny] == map[x][y]) {
			DFS(nx, ny);
		}
	}
}

void initCheck(){
	for(int i=1; i<=12; i++){
		for(int j=1; j<=6; j++){
			check[i][j] = 0;
		}
	}
}

void init(){
	initCheck();
	for(int i=12; i>=2; i--){
		for(int j=6; j>=1; j--){
			for(int k=i-1; k>=1; k--){
				if(map[i][j] == 0 && map[k][j] != 0) {
					map[i][j] = map[k][j];
					map[k][j] = 0;
				}
			}
		}
	}
} 


void print(){
	for(int i=1; i<=12; i++){
		for(int j=1; j<=6; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}