#include<iostream>
#include<algorithm>
#include<cstring>
#define wall 99
#define doc 999
using namespace std;
bool isKey(int x, int y);
void DFS(int x, int y);
void openDoor();
int map[101][101], checkMap[101][101];
int key[27][2];
int T, N, M, keyCnt = 0, cnt = 0, ans = 0;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int main(){
    string str;
    cin >> T;
    for(int t=1; t<=T; t++){
        ans = 0;
        memset(map, 0, sizeof(map));
        memset(key, 0, sizeof(key));
        cin >> N >> M;
        for(int i=1; i<=N; i++){
            cin >> str;
            for(int j=1; j<=M; j++){
                if(str[j-1] == '*') map[i][j] = wall;
                else if(str[j-1] == '$') map[i][j] = doc;
                else if(str[j-1] == '.') map[i][j] = 0;
                else map[i][j] = str[j-1]-'A'+1;
            }
        }
        cin >> str;
        for(int i=0; i<str.size(); i++){
            if(str[i] == '0') continue;
            key[str[i]-'A'+1-32][0] = 1;
        }
        while(1){
            openDoor();
            memset(checkMap, 0, sizeof(checkMap));
            cnt = 0, keyCnt = 0;
            for(int i=1; i<=N; i++){
                if(!checkMap[i][1] && (map[i][1] == 0 || isKey(i, 1)) ) DFS(i, 1);
                if(!checkMap[i][M] && (map[i][M] == 0 || isKey(i, M)) ) DFS(i, M);
            }
            for(int i=1; i<=M; i++){
                if(!checkMap[1][i] && (map[1][i] == 0 || isKey(1, i)) ) DFS(1, i);
                if(!checkMap[N][i] && (map[N][i] == 0 || isKey(N, i)) ) DFS(N, i);
            }
            if(cnt == 0 && keyCnt == 0) break;
            else ans += cnt;
        }
        cout << ans << endl;
    }
}

void DFS(int x, int y) {
    checkMap[x][y] = 1;
    if(map[x][y] == doc) {
        cnt++;
        map[x][y] = 0;
    }
    if(map[x][y] >= 33 && map[x][y] <= 58) {
        keyCnt++;
        key[map[x][y]-32][0] = 1;
        map[x][y] = 0;
    }
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || ny < 1 || nx > N || ny > M || checkMap[nx][ny] || (map[nx][ny] >= 1 && map[nx][ny] <= 26) || map[nx][ny] == wall) continue;
        DFS(nx ,ny);
    }
    return;
}

void openDoor(){
    for(int k=1; k<=26; k++){
        if(key[k][0]) {
            for(int i=1; i<=N; i++){
                for(int j=1; j<=M; j++){
                    if(map[i][j] == k) map[i][j] = 0; 
                }
            }
        }
    }
    return;
}

bool isKey(int x, int y){
    if(map[x][y] >= 33 && map[x][y] <= 58) return true;
    if(map[x][y] == doc) return true;
    return false;
}