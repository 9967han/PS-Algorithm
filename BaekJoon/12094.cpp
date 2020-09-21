#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<time.h>
#define UP 1
#define DO 2
#define RI 3
#define LE 4
using namespace std;
bool moveMap(int moveCase);
void DFS(int cnt);
void printMap();
void copyMap();
void input();
int sequence[11];
int arr[] = {1, 2, 3, 4};
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};
int N, ans=0;
int map[21][21], tempMap[21][21];
int temp[21];
int main(){
    clock_t start, end;
    double result;
    start = clock(); //시간 측정 시작
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	input();
	DFS(0);
	cout << ans;
 
    end = clock(); //시간 측정 끝
    result = (double)(end - start);
    cout << "time : " << result;
	return 0;
}

bool moveMap(int moveCase){
	int flag = 0;
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
			for(int j=1; j<=N; j++) {
				if(temp[j] == 0) map[j][i] = 0;
				else if(map[j][i] != temp[j]){
					map[j][i] = temp[j];
					flag = 1;
				}
			}
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
			for(int j=1; j<=N; j++) {
				if(temp[j] == 0) map[N-j+1][i] = 0;
				else if(map[N-j+1][i] != temp[j]){
					map[N-j+1][i] = temp[j];
					flag = 1;
				}
			}
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
			for(int j=1; j<=N; j++) {
				if(temp[j] == 0) map[i][N-j+1] = 0;
				else if(map[i][N-j+1] != temp[j]){
					map[i][N-j+1] = temp[j];
					flag = 1;
				}	
			}
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
			for(int j=1; j<=N; j++) {
				if(temp[j] == 0) map[i][j] = 0;
				else if(map[i][j] != temp[j]){
					map[i][j] = temp[j];
					flag = 1;
				}
			}
		}
	}
	if(flag == 0) return false;
	else return true;
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
	if(cnt == 10) {
		copyMap();
		for(int i=1; i<=10; i++){
			if(ans < countSum() * pow(2, 10-i)){
				if(!moveMap(sequence[i])) break;
			}
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