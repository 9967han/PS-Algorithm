#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
void input();
void BFS();
int N, M;
int map[1001][1001];
int check[1001][1001];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

struct place{
	int x;
	int y;
	int lev;
	int breakTime;
};

queue<place> q;

int main(){
	input();
	place first = {1, 1, 1, 0};
	check[1][1] = 1;
	q.push(first);
	BFS();
}

void BFS(){
	while(!q.empty()){
		place cur = q.front(); q.pop();
		if(cur.x == N && cur.y == M){
			cout << cur.lev;
			return;
		}
		// cout << "(" << cur.x << " " << cur.y << ") " << cur.lev << " " << cur.breakTime << endl;
		for(int i=0; i<4; i++){
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			int nlev = cur.lev + 1;
			if(check[nx][ny]<=10001 && nx <= N && ny <= M && nx >= 1 && ny >= 1){
				place newPlace;
				newPlace.x = nx; newPlace.y = ny; newPlace.lev = nlev; 
				if(map[nx][ny] == 0 && cur.breakTime == 0){
					newPlace.breakTime = cur.breakTime;
					q.push(newPlace);
					check[nx][ny] += 1;
				} else if(map[nx][ny] == 0 && cur.breakTime == 1 && check[nx][ny] < 10000){
					newPlace.breakTime = cur.breakTime;
					q.push(newPlace);
					check[nx][ny] += 10000;
				}
				if(map[nx][ny] == 1 && cur.breakTime == 0){
					newPlace.breakTime = 1;
					q.push(newPlace);
					check[nx][ny] += 10000;
				}
			}
		}
	}
	cout << "-1";
}

void input(){
	cin >> N >> M;
	string str;
	for(int i=1; i<=N; i++){
		cin >> str;
		for(int j=1; j<=M; j++){
			map[i][j] = str[j-1]-'0';
		}
	}
}