#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
void jump(int sx, int sy);
void printMap();
int N, M, sx, sy, ex, ey, flag = 0;
int map[301][301], visit[301][301];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int main(){
    cin >> N >> M;
    cin >> sx >> sy >> ex >> ey;
    string str;
    for(int i=1; i<=N; i++){
        cin >> str;
        for(int j=0; j<M; j++){
            if(str[j] == '1') map[i][j+1] = 1;
            else map[i][j+1] = 0;
        }
    }
    for(int i=0;; i++){
        memset(visit, 0, sizeof(visit));
        if(flag) {
            cout << i;
            break;
        }
        jump(sx, sy);
    }
}

void jump(int sx, int sy){
    queue<pair<int, int> > q;
    q.push(make_pair(sx, sy));  
    visit[sx][sy] = 1;

    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        if(cur.first == ex && cur.second == ey) flag = true;
        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 1 || ny < 1 || nx > N || ny > M || visit[nx][ny]) continue;
            visit[nx][ny] = 1;
            if(map[nx][ny] == 1) map[nx][ny] = 0;
            else q.push(make_pair(nx, ny));
        }
    }
    return;
}

void printMap(){
    cout << endl;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    return;
}