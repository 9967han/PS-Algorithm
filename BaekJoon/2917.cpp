#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
void input();
void makeDistMap();
queue<pair<int, int> > trees;
priority_queue<pair<int, pair<int, pair<int, int> > > > pq;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int map[501][501], dist[501][501];
int N, M, sx, sy;
int main(){
    memset(dist, -1, sizeof(dist));
    input();
    makeDistMap();
    pq.push(make_pair(dist[sx][sy], make_pair(dist[sx][sy], make_pair(sx, sy))));
    dist[sx][sy] = -1;
    while(!pq.empty()){
        int curDist = pq.top().first;
        int minDist = pq.top().second.first;
        int cx = pq.top().second.second.first;
        int cy = pq.top().second.second.second;
        pq.pop();
        if(map[cx][cy] == 99) {
            cout << minDist;
            return 0;
        }
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 1 || ny < 1 || nx > N || ny > M || dist[nx][ny] == -1) continue;
            pq.push(make_pair(dist[nx][ny], make_pair(min(dist[nx][ny], minDist), make_pair(nx, ny))));
            dist[nx][ny] = -1;
        }
    }
}

void makeDistMap(){
    while(!trees.empty()){
        pair<int, int> cur = trees.front(); trees.pop();
        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 1 || ny < 1 || nx > N || ny > M || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            trees.push(make_pair(nx, ny));
        }
    }
    return;
}

void input(){
    string str;
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> str;
        for(int j=0; j<str.size(); j++){
            if(str[j] == '.') map[i][j+1] = 0;
            else if(str[j] == 'J') map[i][j+1] = 99;
            else if(str[j] == '+') {
                trees.push(make_pair(i, j+1));
                map[i][j+1] = 0;
                dist[i][j+1] = 0;
            } else if(str[j] == 'V') {
                sx = i; sy = j+1;
            }
        }
    }
    return;
}