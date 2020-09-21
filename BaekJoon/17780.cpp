#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
void input();
bool setCountMap();
void printCountMap();
int getVectorNum(int x, int y);
void setNthVector(int n, int nx, int ny);
void Move(int nx, int ny, int cx, int cy, int i);
void printVector();
int N, K, turn=0;
int map[13][13], countMap[13][13];
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};
struct Horse{
	int num;
	int x;
	int y;
	int d;
};
vector<Horse> v[11]; 
int main(){
	input();
	while(turn <= 1000){
		cout << "------- turn" << turn << "----------" << endl;
		if(setCountMap()) {
			cout << turn;
			return 0;
		}
		printCountMap();
		for(int i=1; i<=K; i++){
			if(v[i].size() == 0) continue;
			else cout << "vector" << i << " start !! " << endl;
			for(int j=1; j<=4; j++){
				int cx = v[i][0].x;//current
				int cy = v[i][0].y;
				if(v[i][0].d == j) {
					int nx = cx + dx[j];//next
					int ny = cy + dy[j];
					cout << cx << " " << cy;
					cout << " --> " << nx << " " << ny << endl;
					Move(nx, ny, cx, cy, i);//이동
					break;
				}
			}
		}
		turn++;	
	}
	cout << -1;
	return 0;
}

void Move(int nx, int ny, int cx, int cy, int i){
	if(nx < 1 || ny < 1 || nx > N || ny > N || map[nx][ny] == 2){
		if(v[i][0].d == 1) v[i][0].d = 2;
		else if(v[i][0].d == 2) v[i][0].d = 1;
		else if(v[i][0].d == 3) v[i][0].d = 4;
		else if(v[i][0].d == 4) v[i][0].d = 3;
		int newx = cx + dx[v[i][0].d];
		int newy = cy + dy[v[i][0].d];
		if(newx < 1 || newy < 1 || newx > N || newy > N || map[newx][newy] == 2) return;
		else {
			Move(newx, newy, cx, cy, i);
			return;
		}
	}

	if(countMap[nx][ny]){//이미있으면 업기
		countMap[nx][ny] += countMap[cx][cy];
		countMap[cx][cy] = 0;
		int n = getVectorNum(nx, ny);//이미있던 것의 벡터 넘버 찾아오기
		if(map[nx][ny] == 0) {//흰색
			for(int k=0; k<v[i].size(); k++){
				v[n].push_back(v[i][k]);
			}
		} else if(map[nx][ny] == 1) {//레드
			for(int k=v[i].size()-1; k>=0; k--){
				v[n].push_back(v[i][k]);
			}
		} 
		setNthVector(n, nx, ny);
		v[i].clear();
	}
	else {
		countMap[nx][ny] = v[i].size();
		countMap[cx][cy] = 0;
		setNthVector(i, nx, ny);
		// if(map[nx][ny] == 0) {
		// }
		if(map[nx][ny] == 1) {
			int Reverse = v[i][v[i].size()-1].num;
			if(Reverse == i) return;
			if(v[Reverse].size() != 0) cout << "ERROR";
			for(int k=v[i].size()-1; k>=0; k--){
				v[Reverse].push_back(v[i][k]);
			}
			v[i].clear();
		}
	}	
	if(countMap[nx][ny] >= 4){
		cout << turn-1;
		exit(0);
	}
	// printCountMap();
	return;
}

void setNthVector(int n, int nx, int ny){
	for(int i=0; i<v[n].size(); i++){
		v[n][i].x = nx;
		v[n][i].y = ny;
	}
	return;
}

int getVectorNum(int x, int y){
	for(int i=1; i<=K; i++){
		if(!v[i].size()) continue;
		if(v[i][0].x == x && v[i][0].y == y) return i;
	}
	return 0;
}

bool setCountMap(){
	memset(countMap, 0, sizeof(countMap));
	int cnt = 0;
	for(int i=1; i<=K; i++){
		if(v[i].size() >= 4) return true;
		if(v[i].size() != 0) {
			int x = v[i][0].x;
			int y = v[i][0].y;
			countMap[x][y] = v[i].size();
		}
	}
	return false;
}

void printCountMap(){
	cout << endl;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cout << countMap[i][j] << " ";
		}
		cout << endl;
	}	
	printVector();
	return;
}

void printVector(){
	for(int i=1; i<=K; i++){
		for(int j=0; j<v[i].size(); j++){
			cout << v[i][j].num << " / " <<  v[i][j].x << " " << v[i][j].y << " " << v[i][j].d << " |||"; 
		}
		cout << endl;
	}
	return;
}

void input(){
	cin >> N >> K;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin >> map[i][j];
		}
	}
	int r, c, d;
	for(int i=1; i<=K; i++){
		cin >> r >> c >> d;
		v[i].push_back({i, r, c, d});
	}
	return;
}