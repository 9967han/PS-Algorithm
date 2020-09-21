#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define UP 1
#define DO 2
#define RI 3
#define LE 4
using namespace std;
void moveMap(int moveCase);
void DFS(int cnt);
void printMap();
void copyMap();
void input();
int sequence[6];
int arr[] = {1, 2, 3, 4};
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};
int N, ans=0;
int map[21][21], tempMap[21][21];
int temp[21];
int main(){
	input();
	DFS(0);
	cout << ans;
	return 0;
}

void moveMap(int moveCase){
	memset(temp, 0, sizeof(temp));
	if(moveCase == UP) {
		for(int i=1; i<=N; i++){
			memset(temp, 0, sizeof(temp));
			int beforeNum = 0, tempIdx = 1;
			for(int j=1; j<=N; j++){
				if(map[j][i] == 0) continue;
				if(beforeNum == 0) beforeNum = map[j][i];
				else if(beforeNum == map[j][i]) {//같으면 합치고
					temp[tempIdx] = beforeNum*2;
					tempIdx++;
					beforeNum = 0;
				} else { //다르면 냅둠
					temp[tempIdx] = beforeNum;
					tempIdx++;
					beforeNum = map[j][i];
				}
			}
			if(beforeNum != 0) temp[tempIdx] = beforeNum;
			for(int j=1; j<=N; j++) map[j][i] = temp[j];
		}
	} else if(moveCase == DO) {
		for(int i=1; i<=N; i++){
			memset(temp, 0, sizeof(temp));
			int beforeNum = 0, tempIdx = 1;
			for(int j=N; j>=1; j--){
				if(map[j][i] == 0) continue;
				if(beforeNum == 0) beforeNum = map[j][i];
				else if(beforeNum == map[j][i]) {//같으면 합치고
					temp[tempIdx] = beforeNum*2;
					tempIdx++;
					beforeNum = 0;
				} else { //다르면 냅둠
					temp[tempIdx] = beforeNum;
					tempIdx++;
					beforeNum = map[j][i];
				}
			}
			if(beforeNum != 0) temp[tempIdx] = beforeNum;
			for(int j=1; j<=N; j++) map[N-j+1][i] = temp[j];
		}
	} else if(moveCase == RI) {
		for(int i=1; i<=N; i++){
			memset(temp, 0, sizeof(temp));
			int beforeNum = 0, tempIdx = 1;
			for(int j=N; j>=1; j--){
				if(map[i][j] == 0) continue;
				if(beforeNum == 0) beforeNum = map[i][j];
				else if(beforeNum == map[i][j]) {//같으면 합치고
					temp[tempIdx] = beforeNum*2;
					tempIdx++;
					beforeNum = 0;
				} else { //다르면 냅둠
					temp[tempIdx] = beforeNum;
					tempIdx++;
					beforeNum = map[i][j];
				}
			}
			if(beforeNum != 0) temp[tempIdx] = beforeNum;
			for(int j=1; j<=N; j++) map[i][N-j+1] = temp[j];
		}
	} else {
		for(int i=1; i<=N; i++){
			memset(temp, 0, sizeof(temp));
			int beforeNum = 0, tempIdx = 1;
			for(int j=1; j<=N; j++){
				if(map[i][j] == 0) continue;
				if(beforeNum == 0) beforeNum = map[i][j];
				else if(beforeNum == map[i][j]) {//같으면 합치고
					temp[tempIdx] = beforeNum*2;
					tempIdx++;
					beforeNum = 0;
				} else { //다르면 냅둠
					temp[tempIdx] = beforeNum;
					tempIdx++;
					beforeNum = map[i][j];
				}
			}
			if(beforeNum != 0) temp[tempIdx] = beforeNum;
			for(int j=1; j<=N; j++) map[i][j] = temp[j];
		}
	}
	return;
}

int countSum(){
	int sum = 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			sum = max(sum, map[i][j]);
		}
	}
	return sum;
}

void DFS(int cnt){
	if(cnt == 5) {
		copyMap();
		for(int i=1; i<=5; i++){
			moveMap(sequence[i]);
			// printMap();
		}
		ans = max(ans, countSum());
		return;
	}
	for(int i=1; i<=4; i++){
		sequence[cnt+1] = arr[i-1];
		DFS(cnt+1);
	}
	return;
}

void copyMap(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			map[i][j] = tempMap[i][j];
		}
	}
	return;
}

void printMap(){
	cout << endl;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return;
}

void input(){
	int num;
	cin >> N;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cin >> num;
			if(num != 0) tempMap[i][j] = num;
		}
	}
	return;
}