#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void DFS(int x, int y, int cnt, int flag);
void input();
int map[9][9], visit[9][9];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int N, K, peak=0, ans = 0;
vector<pair<int, int> > v;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{   
        ans = 0;
        input();
        for(int i=0; i<v.size(); i++){
            visit[v[i].first][v[i].second] = 1;
            DFS(v[i].first, v[i].second, 1, false);
            visit[v[i].first][v[i].second] = 0;
        }
        cout << "#" << test_case << " " << ans << endl;
	}
	return 0;
}

void DFS(int x, int y, int cnt, int flag){
    ans = max(ans, cnt);
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || ny < 1 || nx > N || ny > N || visit[nx][ny]) continue;
        visit[nx][ny] = 1;
        for(int k=1; k<=K; k++){
            if(flag == false && map[nx][ny] >= map[x][y] && map[nx][ny]-k < map[x][y]) {
                map[nx][ny] -= k;
                DFS(nx, ny, cnt+1, true);
                map[nx][ny] += k;
            }
        }
        if(map[nx][ny] < map[x][y]) DFS(nx, ny, cnt+1, flag);
        visit[nx][ny] = 0;
    }
    return;
}

void input(){
    cin >> N >> K;
    peak = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j];
            if(peak <= map[i][j]) {
                if(peak < map[i][j]) v.clear();
                v.push_back(make_pair(i, j));
                peak = map[i][j];
            }
        }
    }
    return;
}