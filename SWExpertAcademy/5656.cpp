#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
void burst(int x, int y, int depth);
void breakDown(int n);
void setTurn(int cnt);
void setBlock();
void printMap();
int countRock();
int T, K, N, M, map[16][16], tempMap[16][16], turn[5], ans=9876;
int main(){
    cin >> T;
    for(int t=1; t<=T; t++){
        ans = 9876;
        cin >> K >> M >> N;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                cin >> tempMap[i][j];
            }       
        }
        setTurn(1);
        cout << "#" << t << " " << ans << endl;
    }
}

void setTurn(int cnt){
    if(cnt == K+1) {
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                map[i][j] = tempMap[i][j];
            }
        }
        for(int i=1; i<=K; i++) {
            breakDown(turn[i]);
            setBlock();
        }
        ans = min(ans, countRock());
        return;
    }
    for(int i=1; i<=M; i++){
        turn[cnt] = i;
        setTurn(cnt+1);
    }
}

void breakDown(int n) {
    for(int i=1; i<=N; i++){
        if(map[i][n]) {
            burst(i, n, map[i][n]);
            break;
        }
    }
    return;
}

void setBlock(){
    for(int i=1; i<=M; i++){
        vector<int> v;
        for(int j=N; j>=1; j--){
            if(map[j][i]) {
                v.push_back(map[j][i]);
                map[j][i] = 0;
            }
        }
        for(int j=0, k=N; j<v.size(); j++, k--){
            map[k][i] = v[j];
        }
        v.clear();
    }
    return;
}

void burst(int x, int y, int depth) {
    map[x][y] = 0;
    for(int i=x+1; i<x+depth && i<=N; i++) {
        if(map[i][y]) burst(i, y, map[i][y]);
    }

    for(int i=x-1; i>x-depth && i>=1; i--) {
        if(map[i][y]) burst(i, y, map[i][y]);
    }

    for(int i=y+1; i<y+depth && i<=M; i++) {
        if(map[x][i]) burst(x, i, map[x][i]);
    }

    for(int i=y-1; i>y-depth && i>=1; i--) {
        if(map[x][i]) burst(x, i, map[x][i]);
    }
    return;
}

int countRock(){
    int res = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(map[i][j]) res++;
        }
    }
    return res;
}

void printMap(){
    for(int i=1; i<=N; i++){
        cout << endl;
        for(int j=1; j<=M; j++){
            cout << map[i][j] << " ";
        }
    }
    cout << endl;
    return;
}