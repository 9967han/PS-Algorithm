#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define DOOR 3
#define WALL 1
using namespace std;
void input();
void getMinDoorNum();
int T, N, M;
int map[101][101], visit[101][101];
struct person{
    int x;
    int y;
    int map[101][101];
    int visit[101][101];
    vector<pair<int, int> > door;
};
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
queue<person> q;
int main(){
    input();
}

void getMinDoorNum(){
    while(!q.empty()){
        person cur = qA.front(); qA.pop();
        cout << cur.x << " " << cur.y << endl;
        if(cur.x < 1 || cur.y < 1 || cur.x > N || cur.y > M) { // 종료조건
            cout << "door size : " << cur.door.size() << endl; 
            if(cur.door.size() == 5) exit(0);
            continue;
        } 
        for(int i=0; i<4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(visit[cur.door.size()][nx][ny]) continue; // 방문했던 곳 패스
            if(map[nx][ny] == WALL) continue; // 벽이면 패스
            if(map[nx][ny] == DOOR){ // 문이면 등록
                visit[cur.door.size()][nx][ny] = 1;
                cur.door.push_back(make_pair(nx, ny));
                qA.push({nx, ny, cur.door});
            } else { // 땅이면 go
                visit[cur.door.size()][nx][ny] = 1;
                qA.push({nx, ny, cur.door});
            }
        }
    }
    return;
}

void input(){
    cin >> T;
    for(int i=1; i<=T; i++){
        cin >> N >> M;
        string str;
        bool flag = false;
        int tempAx, tempAy, tempBx, tempBy;
        int map[101][101], visit[101][101];
        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));
        for(int i=1; i<=N; i++){
            cin >> str;
            for(int j=1; j<=M; j++){
                if(str[j-1] == '*') map[i][j] = WALL;
                else if(str[j-1] == '.') map[i][j] = 0;
                else if(str[j-1] == '#') map[i][j] = DOOR;
                else {
                    if(!flag) {
                        tempAx = i; tempAy = j;
                        flag = true;
                    } else tempBx = i; tempBy = j;
                    map[i][j] = 0;
                }
            }
        }

            q.push({tempAx, tempAy, map, visit});
            q.push({tempBx, tempBy, map, visit});
        getMinDoorNum();
    }
}