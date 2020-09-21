#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int moveField(int moveCnt);
void DFS(int cnt);
void input();
int N, ans = 0;
int map[51][10], turn[10], visit[10], field[4];
int main(){
	input();
	visit[1] = 1; turn[4] = 1;
	DFS(1);
	cout << ans;
}

int getScore(){
	int score = 0, outCnt = 0, startIdx = 1;
	for(int i=1; i<=N; i++){//이닝별 점수
		memset(field, 0, sizeof(field));
		outCnt = 0;
		for(int j=startIdx; outCnt<3;j++){
			if(j == 10) j = 1;
			if(map[i][turn[j]] == 0) {
				outCnt++;
				if(outCnt == 3) {
					startIdx = j+1;
					break;
				}
			}else {
				score += moveField(map[i][turn[j]]);
			}
		}	
	}
	return score;
}

int moveField(int moveCnt){
	int score = 0;
	if(moveCnt == 4) {
		score += field[1] + field[2] + field[3] + 1;
		memset(field, 0, sizeof(field));
	} else if(moveCnt == 3) {
		score += field[1] + field[2] + field[3];
		field[3] = 1;
		field[2] = 0;
		field[1] = 0;
	} else if(moveCnt == 2) {
		score += field[2] + field[3];
		field[3] = field[1];
		field[2] = 1;
		field[1] = 0;
	} else if(moveCnt == 1) {
		score += field[3];
		field[3] = field[2];
		field[2] = field[1];
		field[1] = 1;
	}
	return score;
}

void DFS(int cnt){
	if(cnt == 10) {
		ans = max(ans, getScore());
		return;
	}

	if(cnt == 4) {
		turn[4] = 1;
		DFS(cnt+1);
	} else {
		for(int i=2; i<=9; i++){
			if(!visit[i]){
				visit[i] = 1;
				turn[cnt] = i;
				DFS(cnt+1);
				visit[i] = 0;
			}
		}
	}
	
	return;
}

void input(){
	cin >> N;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=9; j++){
			cin >> map[i][j];
		}
	}
	return;
}	