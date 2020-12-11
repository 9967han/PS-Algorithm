#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 100000000
using namespace std;
int DFS(int x, int y);
int N, M, ans=0, map[51][51], dp[51][51], visit[51][51];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main(){
    memset(dp, -1, sizeof(dp));
    memset(visit, 0, sizeof(visit));
    string str;
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> str;
        for(int j=0; j<str.size(); j++){
            if(str[j] == 'H') map[i][j+1] = 0;
            else map[i][j+1] = str[j]-'0';
        }
    }
    int ans = DFS(1, 1);    
    if(ans >= INF) cout << "-1";
    else cout << ans;
    return 0;
}

int DFS(int x, int y){
    if(visit[x][y]) return INF;
    int& ret = dp[x][y];
    if(ret != -1) return ret;
    ret = 1;

    visit[x][y] = 1;
    for(int i=0; i<4; i++){
        int nx = x + dx[i] * map[x][y];
        int ny = y + dy[i] * map[x][y];
        if(nx < 1 || ny < 1 || nx > N || ny > M || map[nx][ny] == 0) continue;
        ret = max(ret, DFS(nx, ny)+1);
    }
    visit[x][y] = 0;
    return ret;
}