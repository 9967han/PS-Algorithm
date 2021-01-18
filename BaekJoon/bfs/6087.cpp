#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
void BFS();
int map[101][101], visit[101][101][4];
int W, H, res = 987654321;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
vector<pair<int, int> > v;
string str;
struct pos{
    int x, y, beforeDir, cnt;
};
queue<pos> q;
int main(){
    memset(visit, -1, sizeof(visit));
    cin >> W >> H;
    for(int i=1; i<=H; i++){
        cin >> str;
        for(int j=0; j<str.size(); j++){
            if(str[j] == '.') map[i][j+1] = 0;
            else if(str[j] == '*') map[i][j+1] = 9;
            else v.push_back(make_pair(i, j+1));
        }
    }
    BFS();
    cout << res;
    return 0;
}

void BFS(){
    pair<int, int> first = v[0];
    int ex = v[1].first, ey = v[1].second;
    for(int i=0; i<4; i++) {
        q.push({v[0].first, v[0].second, i, 0});
        visit[v[0].first][v[0].second][i] = 1;
    }
    while(!q.empty()){
        pos cur = q.front(); q.pop();
        if(cur.cnt >= res) continue;
        if(cur.x == ex && cur.y == ey) {
            res = min(res, cur.cnt);
            continue;
        }
        for(int i=0; i<4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx < 1 || ny < 1 || nx > H || ny > W || map[nx][ny] == 9 || ((visit[nx][ny][i] != -1) && (cur.cnt >= visit[nx][ny][i]))) continue;
            if(i == cur.beforeDir) {
                q.push({nx, ny, i, cur.cnt});
                visit[nx][ny][i] = cur.cnt;
            } else {
                q.push({nx, ny, i, cur.cnt+1});
                visit[nx][ny][i] = cur.cnt+1;
            }
        }
    }
    return ;
}
