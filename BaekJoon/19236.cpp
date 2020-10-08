#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void DFS(int x, int y, int curDir, int num);
void copyMap(int A[4][4][2], int B[4][4][2]);
void moveFish(int x, int y, int k);
void input();
int map[4][4][2];
int ans = 0;
int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int main(){
    input();
    ans = map[0][0][0];
    map[0][0][0] = 0;
    DFS(0, 0, map[0][0][1], ans);
    cout << ans;
}

void DFS(int x, int y, int curDir, int num){
    ans = max(ans, num);

    for(int k=1; k<=16; k++) moveFish(x, y, k); // k번째 물고기를 움직인다.
    int temp[4][4][2];
    copyMap(temp, map); // map -> temp로 copy

    for(int k=1; k<5; k++){
        copyMap(map, temp); // temp -> map으로 copy (backTrack)
        int nx = x + dx[curDir]*k;
        int ny = y + dy[curDir]*k;
        if(nx < 0 || ny < 0 || nx > 3 || ny > 3) break;
        if(map[nx][ny][0]) { // 물고기가 있으면
            int tempFishNum = map[nx][ny][0];
            map[nx][ny][0] = 0; // 잡아먹음
            DFS(nx, ny, map[nx][ny][1], num + tempFishNum); 
        }
    }
    return;
}

void copyMap(int A[4][4][2], int B[4][4][2]){ // B -> A로 붙여넣는 함수
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            A[i][j][0] = B[i][j][0];
            A[i][j][1] = B[i][j][1];
        }
    }
    return;
}

void moveFish(int x, int y, int k){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(map[i][j][0] == k) { // 맵을 돌다가 k번째 물고기를 만나면
                for(int l=map[i][j][1]; l<map[i][j][1]+8; l++){ 
                    int dir = l > 8 ? l%8 : l;
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(nx < 0 || ny < 0 || nx > 3 || ny > 3 || ((nx == x) && (ny == y))) continue;
                    //두 물고기의 위치, 방향 서로 바꿔줌
                    int tempFishNum = map[nx][ny][0];
                    int tempFishDir = map[nx][ny][1];
                    map[nx][ny][0] = map[i][j][0];
                    map[nx][ny][1] = dir;
                    map[i][j][0] = tempFishNum;
                    map[i][j][1] = tempFishDir;
                    return;
                }
            }
        }
    }
}

void input(){
    int fishNum, dir=0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cin >> fishNum >> dir;
            map[i][j][0] = fishNum;
            map[i][j][1] = dir;
        }
    }
    return;
}