#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#define MAX 987654321
int getShortest(int asx, int asy, int adx, int ady, int bsx, int bsy, int bdx, int bdy);
void checkVisit(int x, int y);
void printVisit();
using namespace std;
struct pos{
    int x;
    int y;
    int cnt=0;
};
int map[101][101], visit[101][101];
pos prevMap[101][101];
int N, M;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int main(){
    cin >> M >> N;
    int asx, asy, adx, ady, bsx, bsy, bdx, bdy;
    cin >> asy >> asx >> ady >> adx >> bsy >> bsx >> bdy >> bdx;
    int a = getShortest(asx, asy, adx, ady, bsx, bsy, bdx, bdy);
    int b = getShortest(bsx, bsy, bdx, bdy, asx, asy, adx, ady);
    if(a == MAX && b == MAX) cout << "IMPOSSIBLE";
    else cout << min(a, b);
}

int getShortest(int asx, int asy, int adx, int ady, int bsx, int bsy, int bdx, int bdy){
    memset(visit, 0, sizeof(visit));
    memset(prevMap, 0, sizeof(prevMap));
    int res = 0;
    queue<pos> q;
    visit[asx][asy] = 1;
    visit[bsx][bsy] = 1;
    visit[bdx][bdy] = 1;
    q.push({asx, asy, 0});
    prevMap[asx][asy] = {-1, -1};
    while(!q.empty()){
        pos cur = q.front(); q.pop();
        if(cur.x == adx && cur.y == ady) {
            memset(visit, 0, sizeof(visit));
            checkVisit(cur.x, cur.y);
            res += cur.cnt;
            break;
        }
        for(int i=0; i<4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx < 0 || ny < 0 || nx > N || ny > M || visit[nx][ny]) continue;
            visit[nx][ny] = 1;
            q.push({nx, ny, cur.cnt+1});
            prevMap[nx][ny] = {cur.x, cur.y};
        }
    }

    bool flag = false;
    while(!q.empty()) q.pop();
    visit[bsx][bsy] = 1;
    q.push({bsx, bsy, 0});
    while(!q.empty()){
        pos cur = q.front(); q.pop();
        if(cur.x == bdx && cur.y == bdy) {
            flag = true;
            res += cur.cnt;
            break;
        }
        for(int i=0; i<4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx < 0 || ny < 0 || nx > N || ny > M || visit[nx][ny]) continue;
            visit[nx][ny] = 1;
            q.push({nx, ny, cur.cnt+1});
        }
    }
    if(!flag) return MAX;
    return res;
}

void printVisit(){
    for(int i=0; i<=N; i++){
        cout << endl;
        for(int j=0; j<=M; j++){
            cout << visit[i][j] << " ";
        }
    }
    cout << endl;
    return;
}

void checkVisit(int x, int y){
    visit[x][y] = 1;
    while(prevMap[x][y].x != -1 && prevMap[x][y].y != -1){
        int px = prevMap[x][y].x;
        int py = prevMap[x][y].y;
        visit[px][py] = 1;
        x = px;
        y = py;
    }
    return;
}