#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void findHorse(int ithHorse);
void moveHorse(int ithHorse, int x, int y, int d, int ht);
void input();
void printMap();
struct Horse{
	int d;
	int num; 
};
int N, K, turn=1;
int chessMap[13][13];
vector<Horse> map[13][13];
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};
int main(){
	input();	
	for(turn=1; turn<=1000; turn++){
		for(int i=1; i<=K; i++){
			printMap();
			findHorse(i);
		}
	}
	cout << "-1";
	return 0;
}

void findHorse(int ithHorse){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			for(int k=0; k<map[i][j].size(); k++){
				if(map[i][j][k].num == ithHorse) {
					moveHorse(ithHorse, i, j, map[i][j][k].d, k);
					return;
				}
			}
		}
	}
}

void moveHorse(int ithHorse, int x, int y, int d, int ht){
	int nx = x + dx[d], ny = y + dy[d]; 
	if(nx < 1 || ny < 1 || nx > N || ny > N || chessMap[nx][ny] == 2) { // 블루
		if(map[x][y][ht].d == 1) map[x][y][ht].d = 2;
		else if(map[x][y][ht].d == 2) map[x][y][ht].d = 1;
		else if(map[x][y][ht].d == 3) map[x][y][ht].d = 4;
		else map[x][y][ht].d = 3;
		int newx = x + dx[map[x][y][ht].d];
		int newy = y + dy[map[x][y][ht].d];
		if(newx < 1 || newy < 1 || newx > N || newy > N || chessMap[newx][newy] == 2) return;
		moveHorse(ithHorse, x, y, map[x][y][ht].d, ht);
	} else if(chessMap[nx][ny] == 1) { // 레드
		for(int i=map[x][y].size()-1; i>=ht; i--){ // 더해주고
			map[nx][ny].push_back(map[x][y][i]);
		}
		map[x][y].erase(map[x][y].begin() + ht, map[x][y].end()); //원래있던곳에서 지우기
	} else { // 화이트
		for(int i=ht; i<map[x][y].size(); i++){ // 더해주고 
			map[nx][ny].push_back(map[x][y][i]);
		}
		map[x][y].erase(map[x][y].begin() + ht, map[x][y].end()); //원래있던곳에서 지우기
	}

	if(map[nx][ny].size() >= 4){
		cout << turn;
		exit(0);
	}
	return;
}

void input(){
	int x, y, d;
	cin >> N >> K;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin >> chessMap[i][j];
		}
	}
	for(int i=1; i<=K; i++){
		cin >> x >> y >> d;
		map[x][y].push_back({d, i});
	}
	return;
}

void printMap(){
	cout << endl;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cout << map[i][j].size() << " ";
			for(int k=0; k<map[i][j].size(); k++){
				cout << "( " << map[i][j][k].num  << ", " << map[i][j][k]. d << ") ";
			}	
		}
		cout << endl;
	}
	return;
}
