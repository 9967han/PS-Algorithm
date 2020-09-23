#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct shark{
    int x;
    int y;
    int num;
    int dir;
    bool alive;
};
struct scent{
    int whoscent;
    int duration;
};
int findShark(int x, int y);
void makeScent();
void moveShark();
void removeScent();
void input();
bool isEnd();
void printMap();
void printScentMap();
vector<shark> v;
vector<scent> scentMap[21][21];
int map[21][21], dir[401][5][5];
int N, M, K;
int main(){
    input();
    int cnt = 0;
    while(!isEnd() && cnt <= 1000){
        makeScent();
//         printScentMap();
        printMap();
        moveShark();
        removeScent();
        cnt++;
    }
    if(cnt > 1000) cout << "-1" << endl;
    else cout << cnt << endl; 
}
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};

bool isEnd(){
    for(int i=0; i<v.size(); i++){
        if(v[i].alive && v[i].num != 1) return false;
    }
    return true;
}

void makeScent(){
    for(int i=0; i<v.size(); i++){
        if(!v[i].alive) continue;
        int cx = v[i].x;
        int cy = v[i].y;
        int cNum = v[i].num;
        if(scentMap[cx][cy].size()) scentMap[cx][cy][0].duration = K;
        else scentMap[cx][cy].push_back({cNum, K});
    }
    return;
}

void moveShark(){
    for(int i=0; i<v.size(); i++){
        if(!v[i].alive) continue; // 죽었으면 패스
        bool isMove = false, isSave = false;
        int tempX, tempY, tempDir;
        for(int j=1; j<=4; j++){
            int sharkNum = v[i].num;
            int sharkDir = v[i].dir;
            int nx = v[i].x + dx[dir[sharkNum][sharkDir][j]];
            int ny = v[i].y + dy[dir[sharkNum][sharkDir][j]];
        	if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if(scentMap[nx][ny].size() == 0) {//빈 공간
                if(map[nx][ny]) { // 이미 상어 O
                    if(map[nx][ny] > sharkNum) { // 이 상어보다 큰게 들어가있음
                        map[v[i].x][v[i].y] = 0;
                        map[nx][ny] = sharkNum;
                        v[findShark(nx, ny)].alive = false;
                    } else { // 이 상어보다 작은게 들어가있음
                        isMove = true;
                        map[v[i].x][v[i].y] = 0;
                        v[i].alive = false;
                        break;
                    }
                } else { // 이미 상어 X
                    map[v[i].x][v[i].y] = 0;
                    map[nx][ny] = v[i].num;
                }
                v[i].x = nx; v[i].y = ny;
                // cout << v[i].num << ": " << v[i].dir << " -> " << dir[sharkNum][sharkDir][j] << endl;
                v[i].dir = dir[sharkNum][sharkDir][j];
                isMove = true;
                break;
            } else {
                if(sharkNum != scentMap[nx][ny][0].whoscent) continue; // 다른 상어의 냄새가 있음
                else if(!isSave){ // 자신의 냄새가 있으면 (가장 먼저만난) 자신의 냄새를 일단 저장
                    isSave = true;
                    tempX = nx;
                    tempY = ny;
                    tempDir = dir[sharkNum][sharkDir][j];
                }
            }
        }
        if(!isMove) { // 자신의 냄새가 있는 곳으로 가는 경우
            map[v[i].x][v[i].y] = 0;
            v[i].x = tempX;
            v[i].y = tempY;
            v[i].dir = tempDir;
            map[tempX][tempY] = v[i].num; 
        }
    }
    return;
}

void removeScent(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(scentMap[i][j].size()) {
                if(scentMap[i][j][0].duration >= 2) scentMap[i][j][0].duration--;
                else if(scentMap[i][j][0].duration == 1) scentMap[i][j].clear();
            }
        }
    }
    return;
}

int findShark(int x, int y){
    for(int i=0; i<v.size(); i++){
        if(!v[i].alive) continue;
        if(v[i].x == x && v[i].y == y && v[i].alive) return i;
    }
    return 0;
}

void input(){
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j];
            if(map[i][j]) v.push_back({i, j, map[i][j], 0, true});
        }
    }
    int sharkDir[401];
    for(int i=1; i<=M; i++){
        cin >> sharkDir[i];
        for(int j=0; j<v.size(); j++){
        	if(v[j].num == i) {
        		v[j].dir = sharkDir[i];
        		break;
			}
		}
    }
    for(int i=1; i<=M; i++){ // 몇 번 상어
        for(int j=1; j<=4; j++){ // 위 아래 왼 오
            for(int k=1; k<=4; k++){ // 우선순위
                cin >> dir[i][j][k];
            }
        }
    }
    //dir[1][1][1~4] : 1번상어 위쪽일때 우선순위
}

void printMap(){
    cout << endl;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void printScentMap(){
    cout << endl;
    cout << "this is scentMap" << endl;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(!scentMap[i][j].size()) cout << "0 " ;
            else cout << scentMap[i][j][0].duration << " ";
        }
        cout << endl;
    }
}
