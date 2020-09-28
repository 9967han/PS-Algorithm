#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int getAliveCell();
struct cell{
    int x, y, condition, timeToAct, time;
};
vector<cell> v;
int visitMap[651][651], newCellMap[651][651];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1 ,0};
int T, N, M, K;

int main(){
    cin >> T;
    for(int t=1; t<=T; t++){
        memset(visitMap, 0, sizeof(visitMap));
        v.clear();
        cin >> N >> M >> K;
        for(int i=1; i<=N; i++){
            int t;
            for(int j=1; j<=M; j++){
                cin >> t;
                if(t) {
                    v.push_back({300+i, 300+j, 0, t, 0});
                    visitMap[300+i][300+j] = 1;
                }
            }
        }
        cout << "#" << t << " " << getAliveCell() << endl;
    }
}

int getAliveCell(){
    for(int k=1; k<=K; k++){
        memset(newCellMap, 0, sizeof(newCellMap));
        for(int i=0; i<v.size(); i++){
            if(v[i].condition == 2) continue;
            if(v[i].condition == 0) {
                v[i].time++;
                if(v[i].time == v[i].timeToAct) v[i].condition = 1;
            } else if(v[i].condition == 1) {
                v[i].time++;
                if(v[i].time == v[i].timeToAct+1) {
                    int nx, ny;
                    for(int j=0; j<4; j++){
                        nx = v[i].x + dx[j], ny = v[i].y + dy[j];
                        if(visitMap[nx][ny]) continue;
                        newCellMap[nx][ny] = max(newCellMap[nx][ny], v[i].timeToAct);
                    }
                } 
                if(v[i].time == v[i].timeToAct*2) {
                    v[i].condition = 2;
                }
            } 
        }
        for(int i=300-k; i<=300+N+k; i++){
            for(int j=300-k; j<=300+M+k; j++){
                if(newCellMap[i][j]) {
                    v.push_back({i, j, 0, newCellMap[i][j], 0});
                    visitMap[i][j] = 1;
                }
            }
        }
    }

    int ans = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i].condition == 2) continue;
        ans++;
    }
    return ans;
}