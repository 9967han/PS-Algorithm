#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int map[201][201], visit[201][201][31];
int N, M, K;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
int dxx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dyy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
struct pos{
    int x;
    int y;
    int jumpNum;
    int totalJumpNum;
};
queue<pos> q;
int main(){
    cin >> K;
    cin >> M >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> map[i][j];
        }
    }
    q.push({1, 1, 0, 0});
    visit[1][1][0] = 1;
    while(!q.empty()){
        pos cur = q.front(); q.pop();
        if(cur.x == N && cur.y == M) {
            cout << cur.totalJumpNum;
            return 0;
        }
        for(int i=0; i<8; i++){
            int nx = cur.x + dxx[i];
            int ny = cur.y + dyy[i];
            if(nx < 1 || ny < 1 || nx > N || ny > M || map[nx][ny] || visit[nx][ny][cur.jumpNum+1] || cur.jumpNum == K) continue;
            visit[nx][ny][cur.jumpNum+1] = 1;
            q.push({nx, ny, cur.jumpNum+1, cur.totalJumpNum+1});
        }
        for(int i=0; i<4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx < 1 || ny < 1 || nx > N || ny > M || map[nx][ny] || visit[nx][ny][cur.jumpNum]) continue;
            visit[nx][ny][cur.jumpNum] = 1;
            q.push({nx, ny, cur.jumpNum, cur.totalJumpNum+1});
        }
    }
    cout << "-1";
    return 0;
}