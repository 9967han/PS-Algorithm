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
int N, M, k, dir[401][5][5]; // dir : dir[상어번호][바라보는방향][우선순위]
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

void moveShark(){ // 상어를 이동시키는 함수
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
                sharkMap[nx][ny] = min(sharkMap[nx][ny], v[i].size); // 가장 작은번호의 상어만 남겨둠
                v[i].x = nx, v[i].y = ny, v[i].dir = ndir;
                flag = true; // 빈 칸으로 이동했음을 표시
                break;
            }
        }
        if(flag) continue; // 빈 칸으로 이동한 경우 종료
        for(int j=1; j<=4; j++){ // 냄새로 이동하는 경우
            int ndir = dir[v[i].size][v[i].dir][j];
            int nx = v[i].x + dx[ndir];
            int ny = v[i].y + dy[ndir];
            if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if(scentMap[nx][ny][0].size == v[i].size) { // 자신의 냄새일 경우 이동
                sharkMap[nx][ny] = min(sharkMap[nx][ny], v[i].size);
                v[i].x = nx, v[i].y = ny, v[i].dir = ndir;
                break;
            }
        }
    }
    for(int i=0; i<v.size(); i++){ // 죽은 상어 처리
        if(v[i].die) continue;
        if(sharkMap[v[i].x][v[i].y] != v[i].size) v[i].die = true; 
    }
    return;
}

void makeScent(){ // 냄새 뿌리는 함수
    for(int i=0; i<v.size(); i++){
        if(v[i].die) continue;
        if(scentMap[v[i].x][v[i].y].size()) { // 이미 냄새가 있었다면 갱신
            scentMap[v[i].x][v[i].y][0].size = v[i].size;
            scentMap[v[i].x][v[i].y][0].duration = k;
        } else { // 냄새가 없으면 넣어주기
            scentMap[v[i].x][v[i].y].push_back({v[i].size, k});
        }   
    }
    return;
}

void removeScent(){ // 냄새 줄이는 함수
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(scentMap[i][j].size()) {
                scentMap[i][j][0].duration--;
                if(scentMap[i][j][0].duration == 0) { // 남은 시간이 0이 되면 삭제
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

bool checkFinish(){ // 끝났는지 확인하는 함수
    for(int i=0; i<v.size(); i++){
        if(v[i].size != 1 && !v[i].die) return false;
    }
    return true;
}