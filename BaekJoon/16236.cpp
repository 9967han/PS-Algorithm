#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
void input();
void showMap();
struct shark{
	int x;
	int y;
	int time;
};
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int map[101][101];
int visit[101][101];
int N, curSize = 2, ans = 0, totalEatNum = 0, curEatNum = 0;
queue<shark> q;
vector<pair<int, pair<int, int> > > v;
int main(){
	input();
	while(1) {
		// showMap();
		memset(visit, 0, sizeof(visit));
		while(!q.empty()){
			shark cur = q.front(); q.pop();
			for(int i=0; i<4; i++){
				shark newShark;
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if(nx < 1 || ny < 1 || nx > N || ny > N || visit[nx][ny]) continue;
				visit[nx][ny] = 1;
				if(map[nx][ny] != 0 && curSize > map[nx][ny]) v.push_back(make_pair(cur.time+1, make_pair(nx, ny)));
				else if(curSize < map[nx][ny]) continue;
				newShark = {nx, ny, cur.time+1};
				q.push(newShark);
			}
		}
		sort(v.begin(), v.end());
		if(v.size() == 0) {
			cout << ans;
			exit(0);
		} else {
			ans = v[0].first;
			curEatNum++;
			if(curEatNum == curSize){
				curSize++;
				curEatNum = 0;
			}
			map[v[0].second.first][v[0].second.second] = 0;
			shark newShark = {v[0].second.first, v[0].second.second, v[0].first};
			q.push(newShark);
			v.clear();
		}
	}
}

void input(){
	cin >> N;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin >> map[i][j];
			if(map[i][j] == 9) {
				shark first = {i, j, 0};
				q.push(first);
				map[i][j] = 0;
			}
		}
	}
	return;
}

void showMap(){
	cout << endl;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}