#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void input();
void print();
int N, M, T;
int map[101][101];
int check[101][101];
void DFS(int x, int y);
vector<int> v;

int cnt=0, region=0;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int main(){
	input();
	for(int i=1; i<=M; i++){
		for(int j=1; j<=N; j++){
			DFS(i, j);
			if(cnt != 0) {
				region ++;
				v.push_back(cnt);
			}
			sort(v.begin(), v.end());
			cnt = 0;
		}
	}
	cout << region << endl;
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
}

void input(){
	cin >> M >> N >> T;
	int x1, x2, y1, y2;
	for(int i=1; i<=T; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		for(int j=x1+1; j<=x2; j++){
			for(int k=y1+1; k<=y2; k++){
				map[k][j] = 1;
			}
		}
	}
}

void print(){
	for(int i=1; i<=M; i++){
		for(int j=1; j<=N; j++){
			cout <<	map[i][j] << " ";
		}
		cout << endl;
	}
}

void DFS(int x, int y){
	if(map[x][y]) return;
	map[x][y] = 1;
	cnt++;
	for(int i=0; i<=3; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 1 || ny < 1 || nx > M || ny > N || map[nx][ny]) continue;
		DFS(nx, ny);
	}
}