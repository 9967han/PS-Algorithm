#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define INF 500
void DFS(int x, int y, int cnt);
void input();
void printIsland();
void Union(int x, int y);
int getParent(int x);
bool isSameParent(int x, int y);
int getDistanceBetweenTwoPoints(int number, int fixed, int x1, int y1);
int getDistance(vector<pair<int, int> >  v1, vector<pair<int, int> > v2);
int N, M;
int map[11][11], check[11][11];
int parent[7];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int island=0, ans=0;
vector<pair<int, int> > v[6];
vector<pair<int, pair<int, int> > > edges;

int main(){
	input();
	// printIsland();
	
	for(int i=0; i<island; i++){
		for(int j=i+1; j<island; j++){
			int dist = getDistance(v[i], v[j]);
			if(dist != INF) edges.push_back(make_pair(dist, make_pair(i+1, j+1)));
		}
	}

	sort(edges.begin(), edges.end());

	for(int i=1; i<=island; i++){
		parent[i] = i;
	}

	for(int i=0; i<edges.size(); i++){
		int cost = edges[i].first;
		int from = edges[i].second.first;
		int to = edges[i].second.second;
		if(!isSameParent(from, to)){
			Union(from, to);
			ans += cost;
		}
	}

	for(int i=1; i<=island; i++){
		if(getParent(i) != getParent(1)) {
			ans = -1;
		}
	}
	cout << ans;
	return 0;
}

bool isSameParent(int x, int y){
	x = getParent(x);
	y = getParent(y);
	if(x == y) return true;
	else return false;
}

int getParent(int x){
	if(parent[x] == x) return x;
	else return parent[x] = getParent(parent[x]);
}

void Union(int x, int y){
	x = getParent(x);
	y = getParent(y);
	if(x != y) parent[y] = x;
	return ;
}

void DFS(int x, int y, int cnt){
	check[x][y] = 1;
	v[cnt].push_back(make_pair(x, y));

	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(!check[nx][ny] && map[nx][ny] && nx <= N && ny <= M && nx >= 1 && ny >= 1){
			DFS(nx, ny, cnt);
		}
	}
	return ;
}

void printIsland(){
	for(int i=0; i<island; i++){
		for(int j=0; j<v[i].size(); j++){
			cout << v[i][j].first << " " << v[i][j].second << endl;
		}
		cout << endl;
	}
	cout << endl;
	return ;
}

int getDistance(vector<pair<int, int> >  v1, vector<pair<int, int> > v2){ // 섬끼리의 거리 
	int res = INF;
	for(int i=0; i<v1.size(); i++){
		for(int j=0; j<v2.size(); j++){
			if(v1[i].first == v2[j].first){
				int dis = getDistanceBetweenTwoPoints(0, v1[i].first, v1[i].second, v2[j].second); //row는 같고 col이 다름
				if(dis > 1) res = min(res, dis);
			}
			if(v1[i].second == v2[j].second){
				int dis = getDistanceBetweenTwoPoints(1, v1[i].second, v1[i].first, v2[j].first); // col이 같고 row가 다름
				if(dis > 1) res = min(res, dis);
			}
		}
	}
	if(res != INF) return res;
	else return INF;
}

int getDistanceBetweenTwoPoints(int number, int fixed, int x1, int y1){ //점끼리의 거리 
	if(y1 > x1){
		int temp = y1; y1 = x1; x1 = temp;
	}

	for(int i=y1+1; i<x1; i++){
		if(number == 0 && map[fixed][i] == 1) return INF;
		else if(number == 1 && map[i][fixed] == 1) return INF;
	}

	return x1-y1-1;
}

void input(){
	cin >> N >> M;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cin >> map[i][j]; 
		}
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			if(!check[i][j] && map[i][j]){
				DFS(i, j, island);
				island++;
			}
		}
	}
}