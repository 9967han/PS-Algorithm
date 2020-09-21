#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int map[301][301], visit[301][301];
int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
int T, N;
struct horse{
	int x;
	int y;
	int level;
};
queue<horse> q;
int main(){
	cin >> T;	
	for(int i=1; i<=T; i++){
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		int stx, sty, enx, eny;
		cin >> N >> stx >> sty >> enx >> eny;
		q.push({stx+1, sty+1, 0});
		visit[stx+1][sty+1] = 1;
		while(!q.empty()){
			horse cur = q.front(); q.pop();
			if(cur.x == enx+1 && cur.y == eny+1) {
				cout << cur.level << endl;
				while(!q.empty()) q.pop();
				break;
			}
			for(int i=0; i<8; i++){
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if(nx > N || ny > N || nx < 1 || ny < 1 || visit[nx][ny]) continue;
				visit[nx][ny] = 1;
				q.push({nx, ny, cur.level+1}); 
			}
		}
	}	
}