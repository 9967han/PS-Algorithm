#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
void BFS();
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
struct pos{
    int x, y, dir, cnt;
};
struct comp{
    bool operator()(pos A, pos B){
        return A.cnt > B.cnt;
    }
};
vector<pair<int, int> > door;
priority_queue<pos, vector<pos>, comp> q;
string str;
int map[51][51], visit[51][51][4];
int N;

int main(){
    memset(visit, 0, sizeof(visit));
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> str;
        for(int j=1; j<=N; j++){
            if(str[j-1] == '.') map[i][j] = 0;
            else if(str[j-1] == '!') map[i][j] = 1;
            else if(str[j-1] == '*') map[i][j] = 9;
            else if(str[j-1] == '#') door.push_back(make_pair(i, j));
        }
    }
    BFS();
    return 0;
}

void BFS(){
    for(int i=0; i<4; i++){
        q.push({door[0].first, door[0].second, i, 0});
        visit[door[0].first][door[0].second][i] = 1;
    }
    while(!q.empty()){
        pos cur = q.top(); q.pop();
        // cout << cur.x << " " << cur.y << " " << cur.cnt << endl;
        if(cur.x == door[1].first && cur.y == door[1].second){
            cout << max(0, cur.cnt);
            break;
        }
        int nx = cur.x + dx[cur.dir];
        int ny = cur.y + dy[cur.dir];
        if(nx < 1 || ny < 1 || nx > N || ny > N || map[nx][ny] == 9 || visit[nx][ny][cur.dir]) continue;
        if(map[nx][ny] == 0) q.push({nx, ny, cur.dir, cur.cnt});
        else if(map[nx][ny] == 1) {
            q.push({nx, ny, cur.dir, cur.cnt});
            if(cur.dir == 0 || cur.dir == 3) {
                q.push({nx, ny, 1, cur.cnt+1});
                q.push({nx, ny, 2, cur.cnt+1});
            } else if(cur.dir == 1 || cur.dir == 2) {
                q.push({nx, ny, 0, cur.cnt+1});
                q.push({nx, ny, 3, cur.cnt+1});
            }
        } 
        visit[nx][ny][cur.dir] = 1;
    }
    return;
}