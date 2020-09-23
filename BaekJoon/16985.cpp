#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define MAX 987654321
using namespace std;
void changeBoardOrder(int cnt);
void changeBoardOrderFunc();
void saveBeforeChangeOrderMap();
void loadBeforeChangeOrderMap();
void turnBoard(int idx, int type);
void turnDFS(int cnt);
void printMap();
void loadMap();
int BFS(int map[6][6][6]);
int map[6][6][6], tempMap[6][6][6], tempp[6][6][6];
int turnOrder[6], boardOrder[6], orderVisit[6];
int dx[] = {-1, 0, 0, 1, 0, 0};
int dy[] = {0, -1, 1, 0, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};
int ans = MAX;
int flag = 0;
struct pos{
    int x;
    int y;
    int z;
    int jump;
};

int main(){
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            for(int k=1; k<=5; k++){
                cin >> tempMap[i][j][k];
            }
        }
    }
    turnDFS(1);
    if(ans == MAX) cout << "-1";
    else cout << ans;
}

void turnDFS(int cnt){ // 판을 얼마나 돌릴건지 
    if(cnt == 6) { 
        loadMap(); // 초기맵에서 돌리기
        for(int i=1; i<=5; i++) turnBoard(i, turnOrder[i]); // i번째 판을 turnOrder[i]만큼 돌리기
        saveBeforeChangeOrderMap();
        changeBoardOrder(1); // 판들의 위치 바꾸기
        return;
    }
    for(int i=1; i<=4; i++){
        turnOrder[cnt] = i-1;
        turnDFS(cnt+1);
    }
}

void saveBeforeChangeOrderMap(){
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            for(int k=1; k<=5; k++){
                tempp[i][j][k] = map[i][j][k];
            }
        }
    }
    return;
}


void loadBeforeChangeOrderMap(){
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            for(int k=1; k<=5; k++){
                map[i][j][k] = tempp[i][j][k];
            }
        }
    }
    return;

}

void changeBoardOrder(int cnt) {
    if(cnt == 6) { 
        if(ans == 12) return; // 이미 최단거리
        loadBeforeChangeOrderMap();
        changeBoardOrderFunc();
        ans = min(ans, BFS(map));
        return;
    }

    for(int i=1; i<=5; i++){
        if(!orderVisit[i]) {
            orderVisit[i] = 1;
            boardOrder[cnt] = i;
            changeBoardOrder(cnt+1);
            orderVisit[i] = 0;
        }
    }
}

void changeBoardOrderFunc(){// 바꾸기 시작
    int temp[6][6][6];
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            for(int k=1; k<=5; k++){
                temp[i][j][k] = map[boardOrder[i]][j][k];
            }
        }
    }
    
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            for(int k=1; k<=5; k++){
                map[i][j][k] = temp[i][j][k];
            }
        }
    }
    return;
}

int BFS(int map[6][6][6]){
    //init
    int visit[6][6][6];
    memset(visit, 0, sizeof(visit));
    queue<pos> q;
    visit[1][1][1] = 1;

    if(map[1][1][1] && map[5][5][5]) {
        q.push({1, 1, 1, 0});
        while(!q.empty()){
            pos cur = q.front(); q.pop();
            if(cur.x == 5 && cur.y == 5 && cur.z == 5) return cur.jump;
            for(int i=0; i<6; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                int nz = cur.z + dz[i];
                if(nx < 1 || ny < 1 || nz < 1 || nx > 5 || ny > 5 || nz > 5 || visit[nx][ny][nz] || !map[nx][ny][nz]) continue;
                visit[nx][ny][nz] = 1;
                q.push({nx, ny, nz, cur.jump+1});
            }
        }
    }
    return MAX;
}

void turnBoard(int idx, int type){
    int temp[6];
    for(int k=1; k<=type; k++){
        for(int i=1; i<=5; i++) temp[i] = map[idx][1][i];
        for(int i=1; i<=5; i++) map[idx][1][i] = map[idx][i][5];
        for(int i=1; i<=5; i++) map[idx][i][5] = map[idx][5][6-i];
        for(int i=1; i<=5; i++) map[idx][5][6-i] = map[idx][6-i][1];
        for(int i=1; i<=5; i++) map[idx][6-i][1] = temp[i];
    }
    for(int k=1; k<=type; k++){
        for(int i=2; i<=4; i++) temp[i] = map[idx][2][i];
        for(int i=2; i<=4; i++) map[idx][2][i] = map[idx][i][4];
        for(int i=2; i<=4; i++) map[idx][i][4] = map[idx][4][6-i];
        for(int i=2; i<=4; i++) map[idx][4][6-i] = map[idx][6-i][2];
        for(int i=2; i<=4; i++) map[idx][6-i][2] = temp[i];
    }
    return;
}

void loadMap(){
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            for(int k=1; k<=5; k++){
                map[i][j][k] = tempMap[i][j][k];
            }
        }
    }
    return;
}

void printMap(){
    cout << endl;
    for(int i=1; i<=5; i++){
        for(int j=1; j<=5; j++){
            for(int k=1; k<=5; k++){
                cout << map[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return;
}
