#include<iostream>
#include<algorithm>
#include<cstring>
void rotate(int type);
void checkCmd();
using namespace std;
int map[101][101];
int N, M, R, cmd[2000001];
int main(){
    cin >> N >> M >> R; 
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> map[i][j];
        }
    }
    int cnt1=0, cnt2=0, cnt3=0, cnt4=0, cnt5=0, cnt6=0;
    for(int i=1; i<=R; i++){
        cin >> cmd[i];
    }
    checkCmd();
    for(int i=1; i<=R; i++){
        rotate(cmd[i]);
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void checkCmd(){
    for(int i=1; i<=R-4; i++){
        if(cmd[i] == 1 && cmd[i+1] == 1) {
            cmd[i] = 0;
            cmd[i+1] = 0;
            i++;
        }
        if(cmd[i] == 2 && cmd[i+1] == 2) {
            cmd[i] = 0;
            cmd[i+1] = 0;
            i++;
        }
        if(cmd[i] == 3 && cmd[i+1] == 4) {
            cmd[i] = 0;
            cmd[i+1] = 0;
            i++;
        }
        if(cmd[i] == 4 && cmd[i+1] == 3) {
            cmd[i] = 0;
            cmd[i+1] = 0;
            i++;
        }
        if(cmd[i] == 5 && cmd[i+1] == 6) {
            cmd[i] = 0;
            cmd[i+1] = 0;
            i++;
        }
        if(cmd[i] == 6 && cmd[i+1] == 5) {
            cmd[i] = 0;
            cmd[i+1] = 0;
            i++;
        }
        if(cmd[i] == 3 && cmd[i+1] == 3 && cmd[i+2] == 3 && cmd[i+4] == 3) {
            cmd[i] = 0;
            cmd[i+1] = 0;
            cmd[i+2] = 0;
            cmd[i+3] = 0;
            i+=3;
        }
        if(cmd[i] == 4 && cmd[i+1] == 4 && cmd[i+2] == 4 && cmd[i+4] == 4) {
            cmd[i] = 0;
            cmd[i+1] = 0;
            cmd[i+2] = 0;
            cmd[i+3] = 0;
            i+=3;
        }
        if(cmd[i] == 5 && cmd[i+1] == 5 && cmd[i+2] == 5 && cmd[i+4] == 5) {
            cmd[i] = 0;
            cmd[i+1] = 0;
            cmd[i+2] = 0;
            cmd[i+3] = 0;
            i+=3;
        }
        if(cmd[i] == 6 && cmd[i+1] == 6 && cmd[i+2] == 6 && cmd[i+4] == 6) {
            cmd[i] = 0;
            cmd[i+1] = 0;
            cmd[i+2] = 0;
            cmd[i+3] = 0;
            i+=3;
        }
    }
    return;
}

void rotate(int type){
    if(type == 0) return;
    if(type == 1) { // 상하
        for(int i=1; i<=N/2; i++){
            int temp[101];
            for(int j=1; j<=M; j++) temp[j] = map[i][j];
            for(int j=1; j<=M; j++) map[i][j] = map[N-i+1][j];
            for(int j=1; j<=M; j++) map[N-i+1][j] = temp[j];
        }
    } else if(type == 2) { // 좌우
        for(int i=1; i<=M/2; i++){
            int temp[101];
            for(int j=1; j<=N; j++) temp[j] = map[j][i];
            for(int j=1; j<=N; j++) map[j][i] = map[j][M-i+1];
            for(int j=1; j<=N; j++) map[j][M-i+1] = temp[j];
        }
    } else if(type == 3 || type == 4) { // 회전 
        int temp[101][101];
        if(type == 3) {
            for(int i=1; i<=N; i++){
                for(int j=1; j<=M; j++){
                    temp[j][N-i+1] = map[i][j];
                }
            }
        } else if(type == 4) {
            for(int i=1; i<=N; i++){
                for(int j=1; j<=M; j++){
                    temp[M-j+1][i] = map[i][j];
                }
            }
        }
        memset(map, 0, sizeof(map));
        int tempp = N;
        N = M;
        M = tempp;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                map[i][j] = temp[i][j];
            }
        }
    } else if(type == 5 || type == 6) {
        if(type == 5) {
            int temp[51][51];
            for(int i=1; i<=N/2; i++){
                for(int j=1; j<=M/2; j++) temp[i][j] = map[i][j]; // 1 -> temp
                for(int j=1; j<=M/2; j++) map[i][j] = map[i+N/2][j]; // 4 -> 1
                for(int j=1; j<=M/2; j++) map[i+N/2][j] = map[i+N/2][j+M/2]; // 3 -> 4
                for(int j=1; j<=M/2; j++) map[i+N/2][j+M/2] = map[i][j+M/2]; // 2 -> 3
                for(int j=1; j<=M/2; j++) map[i][j+M/2] = temp[i][j]; // temp -> 2
            }
        } else if(type == 6) {
            int temp[51][51];
            for(int i=1; i<=N/2; i++){
                for(int j=1; j<=M/2; j++) temp[i][j] = map[i][j]; // 1 -> temp
                for(int j=1; j<=M/2; j++) map[i][j] = map[i][j+M/2]; // 2 -> 1
                for(int j=1; j<=M/2; j++) map[i][j+M/2] = map[i+N/2][j+M/2]; // 3 -> 2
                for(int j=1; j<=M/2; j++) map[i+N/2][j+M/2] = map[i+N/2][j]; // 4 -> 3
                for(int j=1; j<=M/2; j++) map[i+N/2][j] = temp[i][j]; // temp -> 4
            }
        }
    }
}
