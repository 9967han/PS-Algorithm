#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define DOOR 3
#define WALL 1
using namespace std;
void getMinDoorNum(int sx, int sy, int type);
int getMinNum();
void input();
int T, N, M;
int map[102][102], visit[102][102][3];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
struct person{
    int x, y, cnt;
};
struct cmp{
    bool operator()(person A, person B){
        return A.cnt > B.cnt;
    }
};
priority_queue<person, vector<person>, cmp> pq;
vector<pair<int, int> > v;
int main(){
    input();
}

void getMinDoorNum(int sx, int sy, int type){
    pq.push({sx, sy, 0});
    visit[sx][sy][type] = 0;
    while(!pq.empty()){
        person cur = pq.top(); pq.pop();
        if(cur.x < 0 || cur.y < 0 || cur.x > N+1 || cur.y > M+1) continue;
        for(int i=0; i<4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(visit[nx][ny][type] != -1) continue; // 방문했던 곳 패스
            if(map[nx][ny] == WALL) continue; // 벽이면 패스
            if(map[nx][ny] == DOOR){ // 문이면 등록
                visit[nx][ny][type] = cur.cnt+1;
                pq.push({nx, ny, cur.cnt+1});
            } else { // 땅이면 go
                visit[nx][ny][type] = cur.cnt;
                pq.push({nx, ny, cur.cnt});
            }
        }
    }
}

void input(){
    cin >> T;
    for(int t=1; t<=T; t++){
        cin >> N >> M;
        string str;
        memset(map, 0, sizeof(map));
        memset(visit, -1, sizeof(visit));
        for(int i=1; i<=N; i++){
            cin >> str;
            for(int j=1; j<=M; j++){
                if(str[j-1] == '*') map[i][j] = WALL;
                else if(str[j-1] == '.') map[i][j] = 0;
                else if(str[j-1] == '#') map[i][j] = DOOR;
                else v.push_back(make_pair(i, j));
            }
        }
        getMinDoorNum(v[0].first, v[0].second, 0);
        getMinDoorNum(v[1].first, v[1].second, 1);
        getMinDoorNum(0, 0, 2);
        cout << getMinNum() << "\n";
        v.clear();
    }
    return;
}

int getMinNum(){
    int res = 987654321;
    for(int i=0; i<=N+1; i++){
        for(int j=0; j<=M+1; j++){
            if(visit[i][j][0] == -1 || visit[i][j][1] == -1 || visit[i][j][2] == -1) continue;
            if(map[i][j] == WALL) continue;
            if(map[i][j] == DOOR) res = min(res, visit[i][j][0] + visit[i][j][1] + visit[i][j][2] - 2);
            else res = min(res, visit[i][j][0] + visit[i][j][1] + visit[i][j][2]);
        }
    }
    return res;
}
