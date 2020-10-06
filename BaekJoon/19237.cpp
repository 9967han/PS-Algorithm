#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
struct shark{
    int x;
    int y;
    int size;
    int dir;
    bool die;
};
struct scent{
    int size;
    int duration;
};
void moveShark();
void makeScent();
void removeScent();
bool checkFinish();
void input();
int N, M, k, dir[401][5][5];
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};
int sharkMap[21][21];
vector<shark> v;
vector<scent> scentMap[21][21];

int main(){
    input();
    for(int t=0; t<=1000; t++){
        if(checkFinish()) {
            cout << t;
            return 0;
        }
        makeScent();
        moveShark();
        removeScent();
    }
    cout << "-1";
    return 0;
}

void moveShark(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            sharkMap[i][j] = 999;
        }
    }

    for(int i=0; i<v.size(); i++){
        if(v[i].die) continue;
        bool flag = false;
        for(int j=1; j<=4; j++){
            int ndir = dir[v[i].size][v[i].dir][j];
            int nx = v[i].x + dx[ndir];
            int ny = v[i].y + dy[ndir];
            if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if(!scentMap[nx][ny].size()) {
                sharkMap[nx][ny] = min(sharkMap[nx][ny], v[i].size);
                v[i].x = nx, v[i].y = ny, v[i].dir = ndir;
                flag = true;
                break;
            }
        }
        if(flag) continue; // 빈칸으로 이동
        for(int j=1; j<=4; j++){
            int ndir = dir[v[i].size][v[i].dir][j];
            int nx = v[i].x + dx[ndir];
            int ny = v[i].y + dy[ndir];
            if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if(scentMap[nx][ny][0].size == v[i].size) {
                sharkMap[nx][ny] = min(sharkMap[nx][ny], v[i].size);
                v[i].x = nx, v[i].y = ny, v[i].dir = ndir;
                break;
            }
        }
    }
    for(int i=0; i<v.size(); i++){
        if(v[i].die) continue;
        if(sharkMap[v[i].x][v[i].y] != v[i].size) v[i].die = true;
    }
    return;
}

void makeScent(){
    for(int i=0; i<v.size(); i++){
        if(v[i].die) continue;
        if(scentMap[v[i].x][v[i].y].size()) {
            scentMap[v[i].x][v[i].y][0].size = v[i].size;
            scentMap[v[i].x][v[i].y][0].duration = k;
        } else {
            scentMap[v[i].x][v[i].y].push_back({v[i].size, k});
        }   
    }
    return;
}

void removeScent(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(scentMap[i][j].size()) {
                scentMap[i][j][0].duration--;
                if(scentMap[i][j][0].duration == 0) {
                    scentMap[i][j].clear();
                }
            }
        }
    }
    return;
}

void input(){
    int x, direc;
    cin >> N >> M >> k;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> x;
            if(x) v.push_back({i, j, x, 0, false});
        }
    }
    for(int i=1; i<=M; i++) {
        cin >> direc;
        for(int j=0; j<v.size(); j++){
            if(v[j].size == i) v[j].dir = direc;
        }
    }
    for(int i=1; i<=M; i++){
        for(int j=1; j<=4; j++){
            for(int k=1; k<=4; k++){
                cin >> dir[i][j][k];
            }
        }
    }
    return;
}

bool checkFinish(){
    for(int i=0; i<v.size(); i++){
        if(v[i].size != 1 && !v[i].die) return false;
    }
    return true;
}