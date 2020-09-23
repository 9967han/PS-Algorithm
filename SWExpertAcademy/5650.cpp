#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
void getScore(int sx, int sy, int dir, int cnt);
int changeDir(int dir, int type);
int T, N, map[102][102], ans=0;
int dx[] = {0, 0, 0, 1, -1};
int dy[] = {0, 1, -1, 0, 0};
vector<pair<int, int> > warmhall[11];

int main(){
    cin >> T;
    for(int t=1; t<=T; t++){
        memset(map, 0, sizeof(map));
        for(int i=0; i<=10; i++) warmhall[i].clear();
        cin >> N;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cin >> map[i][j];
                if(map[i][j] >= 6) warmhall[map[i][j]].push_back(make_pair(i, j));
            }
        }
        ans = 0;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(!map[i][j]) {
                    for(int k=1; k<=4; k++) {
                        getScore(i, j, k, 0);
                    }
                }
            }
        }
        cout << "#" << t << " " << ans << endl;
    }
}

void getScore(int sx, int sy, int dir, int cnt){
    int x = sx, y = sy;
    while(1){
        x += dx[dir], y += dy[dir];
        if((x == sx && y == sy) || map[x][y] == -1) { // 종료되는 경우
            ans = max(ans, cnt);
            break; 
        } 
        if(x < 1 || y < 1 || x > N || y > N) { // 벽에 부딪힘
            cnt++;
            dir = changeDir(dir, 5); 
            continue;
        }  
        if(map[x][y] == 0) continue; // 빈공간
        if(map[x][y] >= 6) { // 웜홀
            int tx, ty;
            if(warmhall[map[x][y]][0].first == x && warmhall[map[x][y]][0].second == y) tx = warmhall[map[x][y]][1].first, ty = warmhall[map[x][y]][1].second;
            else tx = warmhall[map[x][y]][0].first, ty = warmhall[map[x][y]][0].second;
            x = tx, y = ty;
        } else { // 1, 2, 3, 4, 4번 블록에 부딪힘
            cnt++;
            dir = changeDir(dir, map[x][y]); 
            continue;
        }
    }
}

int changeDir(int dir, int type) { // 방향을 바꿔주는 함수
    if(type == 5) {
        if(dir == 1) return 2;
        else if(dir == 2) return 1;
        else if(dir == 3) return 4;
        else if(dir == 4) return 3;
    } else if(type == 1) {
        if(dir == 1) return 2;
        else if(dir == 2) return 4;
        else if(dir == 3) return 1;
        else if(dir == 4) return 3;
    } else if(type == 2) {
        if(dir == 1) return 2;
        else if(dir == 2) return 3;
        else if(dir == 3) return 4;
        else if(dir == 4) return 1;
    } else if(type == 3) {
        if(dir == 1) return 3;
        else if(dir == 2) return 1;
        else if(dir == 3) return 4;
        else if(dir == 4) return 2;
    } else if(type == 4) {
        if(dir == 1) return 4;
        else if(dir == 2) return 1;
        else if(dir == 3) return 2;
        else if(dir == 4) return 3;
    }
    return 0;
}
