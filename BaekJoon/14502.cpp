#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int, int> > v, virus;
void DFS(int idx, int cnt);
int map[9][9], wall[3], visit[80], visitMap[9][9];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int N, M, ans = 0;
int main(){
    memset(visit, 0, sizeof(visit));
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> map[i][j];
            if(map[i][j] == 0) v.push_back(make_pair(i, j));
            else if(map[i][j] == 2) virus.push_back(make_pair(i, j));
        }
    }

    DFS(0, 0);
    cout << ans;
}

void DFS(int idx, int cnt){
    if(cnt == 3) {
        int safeCnt = v.size()-3;
        memset(visitMap, 0, sizeof(visitMap));
        map[v[wall[0]].first][v[wall[0]].second] = 1;
        map[v[wall[1]].first][v[wall[1]].second] = 1;
        map[v[wall[2]].first][v[wall[2]].second] = 1;

        queue<pair<int, int> > q;
        for(int i=0; i<virus.size(); i++) q.push(virus[i]);
        while(!q.empty()){
            pair<int, int> cur = q.front(); q.pop();
            for(int i=0; i<4; i++){
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(nx < 1 || ny < 1 || nx > N || ny > M || map[nx][ny] || visitMap[nx][ny]) continue;
                visitMap[nx][ny] = 1;
                safeCnt--;
                q.push(make_pair(nx, ny));
            }
        }
        ans = max(ans, safeCnt);

        map[v[wall[0]].first][v[wall[0]].second] = 0;
        map[v[wall[1]].first][v[wall[1]].second] = 0;
        map[v[wall[2]].first][v[wall[2]].second] = 0;
        return;
    }

    for(int i=idx; i<v.size(); i++){
        if(visit[i]) continue;
        visit[i] = 1;
        wall[cnt] = i;
        DFS(i, cnt+1);
        visit[i] = 0;
    }
}
