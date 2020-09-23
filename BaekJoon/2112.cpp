#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
void DFS(int idx, int cnt);
void input();
bool isSuccess();
void printMap();
int map[14][21];
int N, M, K, ans = 999;
int main(int argc, char** argv)
{
	int test_case, T;
	cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        ans = 999;
        input();
		DFS(1, 0);
        cout << "#" << test_case << " " << ans << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void input(){
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> map[i][j];
        }
    }
    return;
}

void DFS(int idx, int cnt){
    if(ans <= cnt) return; // 가지치기
	if(cnt <= N && isSuccess()) ans = min(ans, cnt);
    if(cnt == N) return; 
    int lineTemp[21];
	for(int i=idx; i<=N; i++){
        for(int j=1; j<=M; j++) {
            lineTemp[j] = map[i][j];
            map[i][j] = 0;
        }
		DFS(i+1, cnt+1);
        for(int j=1; j<=M; j++){
            map[i][j] = 1;
        }
        DFS(i+1, cnt+1);
        for(int j=1; j<=M; j++){
            map[i][j] = lineTemp[j];
        }
	}
}

bool isSuccess(){
	for(int i=1; i<=M; i++){
		int cnt = 1, flag = map[1][i];
		bool ithSuccess = false;
		for(int j=2; j<=N; j++){
			if(flag && map[j][i]){ // 전에도 1, 이번에도 1
				flag = 1;
				cnt++;
			} else if(!flag && map[j][i]){ //전에는 0, 이번에는 1
				flag = 1;
				cnt = 1;
			} else if(!flag && !map[j][i]){ // 전에는 0, 이번에도 0
				flag = 0;
				cnt++;
			} else { // 전에는 1, 이번에는 0
				flag = 0;
				cnt = 1;
			}
			if(cnt >= K) {
				ithSuccess = true;
				break;
			}
		}
		if(!ithSuccess) return false;
	}
	return true;
}