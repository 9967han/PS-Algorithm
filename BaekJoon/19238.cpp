#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#define START 99
#define END 98
using namespace std;
void input();
struct Pos{
    int x;
    int y;
    int dis;
};
int getDisToEnd(int cx, int cy);
bool compareFunc(Pos A, Pos B);
Pos getNearestPerson();
queue<Pos> q;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int map[21][21], visit[21][21];
int destination[21][21][21][21];
int N, M, fuel;
int main(){
    input();
    for(int i=1; i<=M; i++){
        if(q.empty()){ // 모든 사람을 이동시킬 수 없으면
            cout << "-1";
            exit(0);
        }
        Pos nextPerson = getNearestPerson(); // 가장 가까운 사람 찾고
        if(nextPerson.dis >= 0) { // 찾았으면
            fuel -= nextPerson.dis;
        } else{ // 연료가 바닥나면
            cout << "-1";
            exit(0);
        }
        int getDis = getDisToEnd(nextPerson.x, nextPerson.y); // 목적지로 데려다 주고
        if(fuel-getDis >= 0) { // 데려다 줬으면
            fuel -= getDis;
            fuel += getDis*2; 
        } else { // 연료가 바닥나면
            cout << "-1";
            exit(0);
        }
    }
    cout << fuel << endl;
}

int getDisToEnd(int cx, int cy){
    memset(visit, 0, sizeof(visit));
    vector<Pos> find;
    q.push({cx, cy, 0});
    while(!q.empty()){
        Pos curPos = q.front(); q.pop();
        if(destination[cx][cy][curPos.x][curPos.y] == END) {
            while(!q.empty()) q.pop();
            q.push({curPos.x, curPos.y, 0});
            return curPos.dis;
        }
        for(int i=0; i<4; i++){
            int nx = curPos.x + dx[i];
            int ny = curPos.y + dy[i];
            if(nx < 1 || ny < 1 || nx > N || ny > N || visit[nx][ny] || map[nx][ny] == 1) continue;
            visit[nx][ny] = 1;
            q.push({nx, ny, curPos.dis+1});
        }
    }
    return 0;
}

Pos getNearestPerson(){
    memset(visit, 0, sizeof(visit));
    vector<Pos> find;
    while(!q.empty()){
        Pos curPos = q.front(); q.pop();
        if(map[curPos.x][curPos.y] == START) find.push_back(curPos);
        for(int i=0; i<4; i++){
            int nx = curPos.x + dx[i];
            int ny = curPos.y + dy[i];
            if(nx < 1 || ny < 1 || nx > N || ny > N || visit[nx][ny] || map[nx][ny] == 1) continue;
            visit[nx][ny] = 1;
            q.push({nx, ny, curPos.dis+1});
        }
    }
    if(find.size() == 0) return {-1, -1, -1};
    sort(find.begin(), find.end(), compareFunc);
    map[find[0].x][find[0].y] = 0;
    return find[0];
}

bool compareFunc(Pos A, Pos B){
    if(A.dis <= B.dis) {
        if(A.dis == B.dis) {
            if(A.x <= B.x) {
                if(A.x == B.x) {
                    if(A.y < B.y) {
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

void input(){
    int sx, sy, ex, ey;
    cin >> N >> M >> fuel;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j];
        }
    }
    cin >> sx >> sy;
    q.push({sx, sy, 0});
    for(int i=1; i<=M; i++){
        cin >> sx >> sy >> ex >> ey;
        map[sx][sy] = START;
        destination[sx][sy][ex][ey] = END;
    }
    return;
}