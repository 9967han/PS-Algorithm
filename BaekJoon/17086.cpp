#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
void input();
int getSafeDistance(int x, int y);
struct shark{
	int x;
	int y;
	int depth;
};
int N, M, ans=0;
int map[51][51], visit[51][51];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
vector<pair<int, int> > v;
queue<shark> q;

int main(){
	input();
	for(int i=0; i<v.size(); i++){
		memset(visit, 0, sizeof(visit)); 
		int safeDis = getSafeDistance(v[i].first, v[i].second);
		ans = max(ans, safeDis);
	}
	cout << ans;
}

void input(){
	cin >> N >> M;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cin >> map[i][j];
			if(!map[i][j]) v.push_back(make_pair(i, j));
		}
	}
	return;
}

int getSafeDistance(int x, int y){
	int res = 2500;
	visit[x][y] = 1;
	q.push({x, y, 0});
	while(!q.empty()){
		shark cur = q.front(); q.pop();
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[j];
				if(nx < 1 || ny < 1 || nx > N || ny > M || visit[nx][ny]) continue;
				visit[nx][ny] = 1;
				if(!map[nx][ny]) q.push({nx, ny, cur.depth+1});	
				else res = min(res, cur.depth+1);
			}
		}
	}
	return res;
}