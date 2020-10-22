#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;
void turnMap(int sx, int sy, int ex, int ey);
void DFS(int x, int y, int cnt);
int N, Q, L, map[65][65], temp[65][65], tempMap[65][65], check[65][65];
int ansCnt=0, ans=0, ansA=0;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int main(){
    scanf("%d %d", &N, &Q);
    N = pow(2, N);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            check[i][j] = 0;
            scanf("%d", &map[i][j]);
        }
    }
    for(int i=1; i<=Q; i++){
        scanf("%d", &L);
        if(L > 0) turnMap(1, 1, N, N);
        for(int i=1; i<=N; i++){ // 돌면서 얼음지운 맵을 temp에 저장
            for(int j=1; j<=N; j++){
                int cnt = 0;
                for(int k=0; k<4; k++){
                    int nx = i + dx[k], ny = j + dy[k];
                    if(nx < 1 || ny < 1 || nx > N || ny > N || map[nx][ny] == 0) continue;
                    cnt++;
                }   
                if(map[i][j] == 0) temp[i][j] = 0;
                else if(cnt >= 3) temp[i][j] = map[i][j];
                else temp[i][j] = map[i][j]-1;
            }
        }
        for(int i=1; i<=N; i++){ // 저장한 temp -> map으로 복사
            for(int j=1; j<=N; j++){
                map[i][j] = temp[i][j];
            }
        }
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(map[i][j]) ansCnt += map[i][j]; // 얼음의 양
            if(map[i][j] && !check[i][j]) { // 얼음의 최대 크기
                ansA=0;
                check[i][j] = 1;
                DFS(i, j, 1);
            }
            ans = max(ans, ansA);
        }
    }
    printf("%d\n%d", ansCnt, ans);
}

void DFS(int x, int y, int cnt) {
    ansA++;
    for(int i=0; i<4; i++){
        int nx = x+ dx[i], ny = y+ dy[i];
        if(nx < 1 || ny < 1 || nx > N || ny > N || map[nx][ny] == 0 || check[nx][ny] == 1) continue;
        check[nx][ny] = 1;
        DFS(nx, ny, cnt+1);
    }
}

void turnMap(int sx, int sy, int ex, int ey){ // 맵 돌리기
    int nx = sx+ex-1, ny = sy+ey-1, a = pow(2, L);
    if(ex-sx+1 == a && ey-sy+1 == a) {
        int tempMap[65][65];
        for(int l=1; l<=L; l++){
            for(int i=1+l-1; i<=a-l+1; i++){
                for(int j=1+l-1; j<=a-l+1; j++) tempMap[sx+i-1][ey-j+1] = map[sx+j-1][sy+i-1];
                for(int j=1+l-1; j<=a-l+1; j++) tempMap[sx+j-1][sy+i-1] = map[ex-i+1][sy+j-1];
                for(int j=1+l-1; j<=a-l+1; j++) tempMap[ex-i+1][sy+j-1] = map[ex-j+1][ey-i+1];
                for(int j=1+l-1; j<=a-l+1; j++) tempMap[ex-j+1][ey-i+1] = map[sx+i-1][ey-j+1];
            }
        }
        for(int i=sx; i<=ex; i++){
            for(int j=sy; j<=ey; j++){
                map[i][j] = tempMap[i][j];
            }
        }
        return;
    }
    turnMap(sx, sy, nx/2, ny/2);
    turnMap(nx/2+1, sy, ex, ny/2);
    turnMap(sx, ny/2+1, nx/2, ey);
    turnMap(nx/2+1, ny/2+1, ex, ey);
}
