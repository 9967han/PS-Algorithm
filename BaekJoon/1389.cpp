#include<iostream>
#include<algorithm>
#define MAX 101
using namespace std;
void input();
void print();
int N, M;
int map[101][101];

int main(){
	input();
	for(int i=1; i<=N; i++){//거쳐감
		for(int j=1; j<=N; j++){//출발
			for(int k=1; k<=N; k++){//도착
				map[j][k] = min(map[j][k], (map[j][i] + map[i][k]));
			}
		}
	}
	// print();
	
	int result = MAX;
	int resultNum = 0;
	for(int i=N; i>=1; i--){
		int len = 0;
		for(int j=1; j<=N; j++){
			len += map[i][j];
		}
		if(result >= len) {
			result = len;
			resultNum = i;
		}
	}
	cout << resultNum;
}

void input(){
	cin >> N >> M;
	int x, y;
	for(int i=1; i<=M; i++){
		cin >> x >> y;
		map[x][y] = 1;
		map[y][x] = 1;
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(i == j) map[i][j] = 0;
			else if(map[i][j] == 1) continue;
			else map[i][j] = MAX;
		}
	}
}

void print(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cout << map[i][j];
		}
		cout << endl;
	}
}