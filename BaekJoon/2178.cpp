#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
void BFS();
void input();
void printMap();
int map[101][101];
int check[101][101];
int N, M;
string str;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
struct location{
	int x;
	int y;
	int level;
};
queue<location> q;
int main(){
	input();
	location first; first.x = 1; first.y = 1; first.level = 1;
	q.push(first);
	
	BFS();

}
void BFS(){
	while(!q.empty()){
		location cur = q.front(); q.pop();
		if(cur.x == N && cur.y == M) {
			cout << cur.level;
			return;
		}
		for(int i=0; i<4; i++){
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if(!check[nx][ny] && map[nx][ny] && nx >= 1 && ny >= 1 && nx <= N && ny <= M){
				check[nx][ny] = 1;
				location newloc; newloc.x = nx; newloc.y = ny; newloc.level = cur.level+1;
				q.push(newloc);
			}
		}
	}
}

void input(){
	cin >> N >> M;
	for(int i=1; i<=N; i++){
		cin >> str;
		for(int j=0; j<str.size(); j++){
			map[i][j+1] = str[j]-'0';
		}
	}
}

void printMap(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}