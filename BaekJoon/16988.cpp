#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
void getScore(int x, int y, int & score, bool & flag);
void DFS(int idx, int cnt);
int getMaxScore();
int map[21][21], visit[401], visitMap[21][21];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int N, M, ans = 0;
vector<pair<int, int> > v;
int main(){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> map[i][j];
            if(!map[i][j]) v.push_back(make_pair(i, j));
        }
    }

    DFS(0, 0);
    cout << ans << endl;
}

void DFS(int idx, int cnt){
    if(cnt == 2) {
        memset(visitMap, 0, sizeof(visitMap));
        ans = max(ans, getMaxScore());
        return;
    }

    for(int i=idx; i<v.size(); i++){
        if(visit[i]) continue;
        visit[i] = 1;
        map[v[i].first][v[i].second] = 1;

        DFS(i, cnt+1);

        visit[i] = 0;
        map[v[i].first][v[i].second] = 0;
    }
}

int getMaxScore(){
    int cnt = 0, score = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(!visitMap[i][j] && map[i][j] == 2) {
                bool flag = false; 
                getScore(i, j, ++score, flag);
                if(!flag) cnt = score;
                else score -= (score-cnt);
            }
        }
    }
    return cnt;
}

void getScore(int x, int y, int & score, bool & flag){
    visitMap[x][y] = 1;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || ny < 1 || nx > N || ny > M || visitMap[nx][ny] || map[nx][ny] == 1) continue;
        if(map[nx][ny] == 0) flag = true;
        else if(map[nx][ny] == 2) getScore(nx, ny, ++score, flag);
    }
    return;
}