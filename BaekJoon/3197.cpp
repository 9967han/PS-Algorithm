#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
void waterBFS();
bool birdBFS();
int N, M, ex, ey;
int map[1501][1501], visit[1501][1501];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
queue<pair<int, int> > curWaterQ, nextWaterQ, curBirdQ, nextBirdQ;
string str;

int main(){
    cin >> N >> M;
    memset(visit, 0, sizeof(visit));
    memset(map, 0, sizeof(map));
    for(int i=1; i<=N; i++){
        cin >> str;
        for(int j=1; j<=M; j++){
            if(str[j-1] == '.'){
                curWaterQ.push(make_pair(i, j));
            } else if(str[j-1] == 'X'){
                map[i][j] = 1;
            } else if(str[j-1] == 'L'){
                map[i][j] = 99;
                ex = i, ey = j;
                curWaterQ.push(make_pair(i, j));
            } 
        }
    }
    visit[ex][ey] = 1;
    curBirdQ.push(make_pair(ex, ey));
    for(int t=1;;t++){
        waterBFS();
        if(birdBFS()) {
            cout << t;
            return 0;
        }
        curWaterQ = nextWaterQ;
        while(!nextWaterQ.empty()) {
            curWaterQ.push(nextWaterQ.front());
            nextWaterQ.pop();
        }
        while(!nextBirdQ.empty()) {
            curBirdQ.push(nextBirdQ.front());
            nextBirdQ.pop();
        }
    }
}

void waterBFS(){
    while(!curWaterQ.empty()){
        pair<int, int> cur = curWaterQ.front(); curWaterQ.pop();
        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 1 || ny < 1 || nx > N || ny > M) continue;
            if(map[nx][ny] == 1) {
                map[nx][ny] = 0;
                nextWaterQ.push({nx, ny});
            }
        }
    }
    return;
}

bool birdBFS(){
    while(!curBirdQ.empty()){
        pair<int, int> cur = curBirdQ.front(); curBirdQ.pop();
        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 1 || ny < 1 || nx > N || ny > M || visit[nx][ny]) continue;
            visit[nx][ny] = 1;
            if(map[nx][ny] == 99) return true;
            else if(map[nx][ny] == 1) nextBirdQ.push({nx, ny});
            else curBirdQ.push(make_pair(nx, ny));
        }
    }
    return false;
}