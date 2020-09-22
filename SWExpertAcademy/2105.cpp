#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
void DFS(int stx, int sty, int x, int y, int dir);
bool isVisited(int nx, int ny);
int map[21][21], visitMap[21][21];
int N, T, res=0;
int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, -1, 1};
set<int> s;
int main(){
    memset(visitMap, 0, sizeof(visitMap));
    cin >> T;
    for(int t=1; t<=T; t++){
        cin >> N;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cin >> map[i][j];
            }
        }
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                memset(visitMap, 0, sizeof(visitMap));
                s.clear();
                DFS(i, j, i, j, 0);
            }
        }
        if(res == 0) res = -1; 
        cout << "#" << t << " " << res << endl;
        res = 0;
    }
}

void DFS(int stx, int sty, int x, int y, int dir){
    if(x == stx && y == sty && dir == 3) {
        if(res < s.size()) res = s.size();
        return;
    }
    int nx, ny;
    for(int i=0; i<2; i++){
        if(i == 0) nx = x + dx[dir], ny = y + dy[dir];
        else nx = x + dx[dir+1], ny = y + dy[dir+1];
        if(nx < 1 || ny < 1 || nx > N || ny > N || visitMap[nx][ny] || isVisited(nx, ny)) continue;
        visitMap[nx][ny] = 1;
        s.insert(map[nx][ny]);
        if(i == 0) DFS(stx, sty, nx, ny, dir);
        else DFS(stx, sty, nx, ny, dir+1);
        visitMap[nx][ny] = 0;
        s.erase(map[nx][ny]);
    }
}

bool isVisited(int nx, int ny){
    if(s.find(map[nx][ny]) == s.end()) return false;
    return true;
}
