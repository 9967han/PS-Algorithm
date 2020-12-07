#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
bool isEnd(int x, int y, int flag);
int N, M, sx, sy;
int map[51][51], visit[51][51][4][2][2];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
struct pos{
    int x, y, cnt, beforeDir, findFirst, findSecond;
};
vector<pair<int, int> > endv;
queue<pos> q;

int main(){
    memset(visit, 0, sizeof(visit));
    cin >> N >> M;
    string str;
    for(int i=1; i<=N; i++){
        cin >> str;
        for(int j=0; j<M; j++){
            if(str[j] == '.') map[i][j+1] = 0;
            else if(str[j] == '#') map[i][j+1] = 9;
            else if(str[j] == 'S') {
                map[i][j+1] = 0;
                sx = i, sy = j+1;
            }
            else if(str[j] == 'C') {
                map[i][j+1] = 1;
                endv.push_back(make_pair(i, j+1));
            }
        }
    }
    q.push({sx, sy, 0, -1, 0, 0});
    while(!q.empty()) {
        pos cur = q.front(); q.pop();
        if((cur.findFirst && isEnd(cur.x, cur.y, 2)) || (cur.findSecond && isEnd(cur.x, cur.y, 1))) {
            cout << cur.cnt;
            return 0;   
        } 
        if(cur.x == endv[0].first && cur.y == endv[0].second) cur.findFirst = 1;
        if(cur.x == endv[1].first && cur.y == endv[1].second) cur.findSecond = 1;

        for(int i=0; i<4; i++){
            if(cur.beforeDir == i) continue;
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx < 1 || ny < 1 || nx > N || ny > M || visit[nx][ny][i][cur.findFirst][cur.findSecond] || map[nx][ny] == 9) continue;
            visit[nx][ny][i][cur.findFirst][cur.findSecond] = 1;
            q.push({nx, ny, cur.cnt+1, i, cur.findFirst, cur.findSecond});
        }
    }
    cout << "-1";
    return 0;
}
bool isEnd(int x, int y, int flag){
    if(flag == 1 && x == endv[0].first && y == endv[0].second) return true;
    else if(flag == 2 && x == endv[1].first && y == endv[1].second) return true;
    else return false;
}