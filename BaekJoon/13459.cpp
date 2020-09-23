#include<algorithm>
#include<queue>
#include<iostream>
#include<string>
using namespace std;
void move(int& x, int& y, int dirX, int dirY);
void input();
void print();

int N, M;
int endx, endy, rdx, rdy, blx, bly, ans=987;
int map[11][11];
bool check[11][11][11][11];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

struct balls{
	int depth;
	int rx, ry, bx, by;
};

int main(){
	input();

	queue<balls> q;
	balls ball = {0, rdx, rdy, blx, bly};
	check[rdx][rdy][blx][bly] = 1;
	q.push(ball);

	while(!q.empty()){
		balls b = q.front(); q.pop();
		// cout << "nrx : " << b.rx << "nry : " << b.ry << "blx : " << b.bx << "bly : " << b.by << endl; 

		if(b.depth > 10) break;

		if(b.rx == endx && b.ry == endy) {
			ans = min(ans, b.depth);
			break;
		}

		for(int i=0; i<4; i++){
			int nrx, nry, nbx, nby;
			nrx = b.rx, nry = b.ry, nbx = b.bx, nby = b.by;
			move(nrx, nry, dx[i], dy[i]);
			move(nbx, nby, dx[i], dy[i]);

			if(nbx == endx && nby == endy) continue;

			if(nrx == nbx && nry == nby) {
				switch(i){
					case 0:
						b.rx > b.bx ? nrx++ : nbx++; break;
					case 1:
						b.ry > b.by ? nry++ : nby++; break;
					case 2:
						b.ry > b.by ? nby-- : nry--; break;
					case 3:
						b.rx > b.bx ? nbx-- : nrx--; break;
				}
			}

			if(!check[nrx][nry][nbx][nby]){
				balls next = {b.depth+1, nrx, nry, nbx, nby};
				q.push(next);
				check[nrx][nry][nbx][nby] = 1;
			}
		}
	}
	if(ans == 987) cout << -1;
	else cout << ans;
}

void move(int& x, int& y, int dirX, int dirY){	
	while(1){
		x = x + dirX;
		y = y + dirY;
		if(map[x][y] == -1){ // 벽을 만나면  
			x = x - dirX;
			y = y - dirY;
			break;
		} else if(map[x][y] == 9) {
			break; 
		} 
	}
	return;
}

void input(){
	cin >> N >> M;
	string str;
	for(int i=1; i<=N; i++){
		cin >> str;
		for(int j=0; j<M; j++){
			if(str[j] == '#'){
				map[i][j+1] = -1;
			} else if(str[j] == '.'){
				map[i][j+1] = 0;
			} else if(str[j] == 'R'){
				rdx = i, rdy = j+1;
				map[i][j+1] = 1;
			} else if(str[j] == 'B'){
				blx = i, bly = j+1;
				map[i][j+1] = 2;
			} else if(str[j] == 'O'){
				endx = i, endy = j+1;
				map[i][j+1] = 9;
			}
		}
	}
	return;
}

void print(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return;
}