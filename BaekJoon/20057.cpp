#include<iostream>
#include<algorithm>
using namespace std;
void move(int x, int y, int cnt, int limit, int dir);
void sweep(int x, int y, int dir);
int N, ans = 0;
int map[501][501];
int dx[] = {0, 0, 1, 0, -1};
int dy[] = {0, -1, 0, 1, 0};
int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j];
        }
    }
    int sx = N/2+1, sy = N/2+1; // 중앙에서 시작
    move(sx, sy, 1, 1, 1);
    cout << ans;
}

void move(int x, int y, int cnt, int limit, int dir) {
    if(x == 1 && y == 1) return;
    int nx = x + dx[dir], ny = y + dy[dir];
    sweep(nx, ny, dir);
    if(cnt == limit) {
        if(dir == 1) move(nx, ny, 1, limit, dir+1); // 왼쪽 -> 아래쪽
        else if(dir == 2) move(nx, ny, 1, limit+1, dir+1); // 아래쪽 -> 오른쪽
        else if(dir == 3) move(nx, ny, 1, limit, dir+1); // 오른쪽 -> 위쪽
        else move(nx, ny, 1, limit+1, 1); // 위쪽 -> 왼쪽
    } else {
        move(nx, ny, cnt+1, limit, dir);
    }   
}

void sweep(int x, int y, int dir){ // 해당 위치와 방향
    int total = map[x][y], cnt = 0;
    int sweepMap[5][5] = {{0, 0, 2, 0, 0}, {0, 10, 7, 1, 0}, {5, 0, 0, 0, 0}, {0, 10, 7, 1, 0}, {0, 0, 2, 0, 0}};
    map[x][y] = 0; // 해당 위치는 0으로 만듦.
    if(dir == 1) { // 왼쪽
        for(int i=0; i<5; i++){ 
            for(int j=0; j<5; j++){
                int nx = x-2+i, ny = y-2+j;
                cnt += (sweepMap[i][j] * total)/100;
                if(nx < 1 || ny < 1 || nx > N || ny > N) ans += (sweepMap[i][j] * total)/100; // 밖으로 나감
                else map[nx][ny] += (sweepMap[i][j] * total)/100; // 맵의 비율만큼 곱해서 더해줌.
            }
        }
        if(y-1 < 1) ans += (total-cnt); // 밖으로 나감
        else map[x][y-1] += (total-cnt); // a(나머지)를 더해줌
    } else if(dir == 2) { // 아래쪽
        for(int i=4; i>=0; i--){
            for(int j=0; j<5; j++){
                int nx = x-2+(4-i), ny = y-2+j;
                cnt += (sweepMap[j][i] * total)/100;
                if(nx < 1 || ny < 1 || nx > N || ny > N) ans += (sweepMap[j][i] * total)/100;
                else map[nx][ny] += (sweepMap[j][i] * total)/100;
            }
        }
        if(x+1 > N) ans += (total-cnt);
        else map[x+1][y] += (total-cnt);
    } else if(dir == 3) { // 오른쪽 
        for(int i=0; i<5; i++){
            for(int j=4; j>=0; j--){
                int nx = x-2+i, ny = y-2+(4-j);
                cnt += (sweepMap[i][j] * total)/100;
                if(nx < 1 || ny < 1 || nx > N || ny > N) ans += (sweepMap[i][j] * total)/100;
                else map[nx][ny] += (sweepMap[i][j] * total)/100;
            }
        }
        if(y+1 > N) ans += (total-cnt);
        else map[x][y+1] += (total-cnt);
    } else { // 위쪽
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                int nx = x-2+i, ny = y-2+j;
                cnt += (sweepMap[j][i] * total)/100;
                if(nx < 1 || ny < 1 || nx > N || ny > N) ans += (sweepMap[j][i] * total)/100;
                else map[nx][ny] += (sweepMap[j][i] * total)/100;
            }
        }
        if(x-1 < 1) ans += (total-cnt);
        else map[x-1][y] += (total-cnt);
    }
    return;
}