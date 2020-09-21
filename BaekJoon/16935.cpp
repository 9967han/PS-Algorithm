
#include<iostream>
#include<algorithm>
#include<cstring>
void rotate(int type);
using namespace std;
int map[101][101];
int N, M, R, cmd;
int main(){
    cin >> N >> M >> R; 
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> map[i][j];
        }
    }
    for(int i=1; i<=R; i++){
        cin >> cmd;
        rotate(cmd);
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void rotate(int type){
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
