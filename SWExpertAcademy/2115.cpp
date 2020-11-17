#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
void getMaxHoney(int idx, int cnt, int maxCnt, int type);
void getTwoPair(int cnt);
int map[11][11], pos[5];
int N, T, M, C, ans = 0, aHoney = 0, bHoney = 0;
int honey[11][2], visit[11];
int main(){
    cin >> T;
    for(int t=1; t<=T; t++){
        ans = 0;
        cin >> N >> M >> C;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cin >> map[i][j];
            }
        }
        getTwoPair(1);
        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}

void getTwoPair(int cnt){
    if(cnt == 5) {
        int fx = pos[1], fy = pos[2];
        int sx = pos[3], sy = pos[4];
        bool flag1 = (fx != sx && sy+M <= N+1 && fy+M <= N+1 && fx < sx);
        bool flag2 = (fx == sx && sy+M <= N+1 && fy+M <= N+1 && fy+M <= sy);
        if(!flag1 && !flag2) return;
        for(int i=0; i<M; i++) {
            honey[i+1][0] = map[fx][fy+i];
            honey[i+1][1] = map[sx][sy+i];
        }
        // cout << fx << fy << " " << sx << sy << endl;
        aHoney = 0, bHoney = 0;
        for(int i=M; i>=1; i--){
            memset(visit, 0, sizeof(visit));
            getMaxHoney(1, 0, i, 0);
            memset(visit, 0, sizeof(visit));
            getMaxHoney(1, 0, i, 1);
        }
        ans = max(ans, aHoney + bHoney);
        return;
    }

    for(int i=1; i<=N; i++){
        pos[cnt] = i;
        getTwoPair(cnt+1);
    }
}

void getMaxHoney(int idx, int cnt, int maxCnt, int type){
    if(cnt == maxCnt) {
        int honeySum = 0, honeyIncomeSum = 0;
        for(int i=1; i<=M; i++){
            if(visit[i]) {
                honeySum += honey[i][type];
                honeyIncomeSum += pow(honey[i][type], 2);
                if(honeySum > C) return;
            }
        }
        if(type == 0) aHoney = max(aHoney, honeyIncomeSum);
        if(type == 1) bHoney = max(bHoney, honeyIncomeSum);
        // cout << "HONEY : " << aHoney << " " << bHoney << endl;
        return;
    }

    for(int i=idx; i<=M; i++){
        if(visit[i]) continue;
        visit[i] = 1;
        getMaxHoney(i, cnt+1, maxCnt, type);
        visit[i] = 0;
    } 
}