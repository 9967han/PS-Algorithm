#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
void moveLeft(int x, int y, int lev);
void moveRight(int x, int y, int lev);
void moveUp(int x, int y, int lev);
void moveDown(int x, int y, int lev);
struct pos{
    int x;
    int y;
    int lev;
};
queue<pos> q;
int N, M, R, C, L, T, visitNum, map[50][50], visit[50][50];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int main(){
    cin >> T;
    for(int t=1; t<=T; t++){
        memset(visit, 0, sizeof(visit));
        cin >> N >> M >> R >> C >> L;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin >> map[i][j];
            }
        }
        q.push({R, C, 1});
        visit[R][C] = 1, visitNum = 1;
        while(!q.empty()) {
            pos cur = q.front(); q.pop();
            int cx = cur.x, cy = cur.y;
            if(map[cx][cy] == 1) {
                moveLeft(cx, cy, cur.lev);
                moveRight(cx, cy, cur.lev);
                moveUp(cx, cy, cur.lev);
                moveDown(cx, cy, cur.lev);
            } else if(map[cx][cy] == 2) {
                moveUp(cx, cy, cur.lev);
                moveDown(cx, cy, cur.lev);
            } else if(map[cx][cy] == 3) {
                moveLeft(cx, cy, cur.lev);
                moveRight(cx, cy, cur.lev);
            } else if(map[cx][cy] == 4) {
                moveRight(cx, cy, cur.lev);
                moveUp(cx, cy, cur.lev);                
            } else if(map[cx][cy] == 5) {
                moveRight(cx, cy, cur.lev);
                moveDown(cx, cy, cur.lev);                
            } else if(map[cx][cy] == 6) {
                moveDown(cx, cy, cur.lev);
                moveLeft(cx, cy, cur.lev);                
            } else if(map[cx][cy] == 7) {
                moveUp(cx, cy, cur.lev);
                moveLeft(cx, cy, cur.lev);                
            }    
        }
        cout << "#" << t << " " << visitNum << endl;
    }
}

void moveLeft(int x, int y, int lev) { 
    y--;
    if(y < 0 || !map[x][y] || visit[x][y] || lev == L) return;
    if(map[x][y] == 2 || map[x][y] == 6 || map[x][y] == 7) return;
    visit[x][y] = 1, visitNum++;
    q.push({x, y, lev+1});
    return;
}

void moveRight(int x, int y, int lev) { 
    y++;
    if(y >= M || !map[x][y] || visit[x][y] || lev == L) return;
    if(map[x][y] == 2 || map[x][y] == 4 || map[x][y] == 5) return;
    visit[x][y] = 1, visitNum++;
    q.push({x, y, lev+1});
    return;
}

void moveUp(int x, int y, int lev) { 
    x--;
    if(x < 0 || !map[x][y] || visit[x][y] || lev == L) return;
    if(map[x][y] == 3 || map[x][y] == 4 || map[x][y] == 7) return;
    visit[x][y] = 1, visitNum++;
    q.push({x, y, lev+1});
    return;
}

void moveDown(int x, int y, int lev) { 
    x++;
    if(x >= N || !map[x][y] || visit[x][y] || lev == L) return;
    if(map[x][y] == 3 || map[x][y] == 5 || map[x][y] == 6) return;
    visit[x][y] = 1, visitNum++;
    q.push({x, y, lev+1});
    return;
}