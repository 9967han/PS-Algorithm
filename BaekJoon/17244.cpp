#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
void getOrder(int idx, int cnt);
int BFS(int ssx, int ssy, int eex, int eey);
int map[51][51], visitMap[51][51], check[6], order[6];
int N, M, sx, sy, ex, ey, ans=987654321;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
vector<pair<int, int> > v;
queue<pair<int, pair<int, int> > > q;
int main(){
    cin >> N >> M;
    string str;
    for(int i=1; i<=M; i++){
        cin >> str;
        for(int j=1; j<=N; j++){
            if(str[j-1] == '#') {
                map[i][j] = 1;
            } else if(str[j-1] == 'S'){
                sx = i, sy = j;
                map[i][j] = 0;
            } else if(str[j-1] == '.'){
                map[i][j] = 0;
            } else if(str[j-1] == 'X'){ 
                map[i][j] = 0;
                v.push_back(make_pair(i, j));
            } else if(str[j-1] == 'E'){
                ex = i, ey = j;
                map[i][j] = 99;
            }
        }
    }
    getOrder(0, 0);
    cout << ans;
}

void getOrder(int idx, int cnt) {
    if(cnt == v.size()) {
        int len;
        if(v.size() == 0) {
            int len = BFS(sx, sy, ex, ey);
            ans = min(ans, len);
            return;
        }
        len = BFS(sx, sy, v[order[0]].first, v[order[0]].second);
        for(int i=0; i<v.size()-1; i++){
            len += BFS(v[order[i]].first, v[order[i]].second, v[order[i+1]].first, v[order[i+1]].second);
            if(len > ans) return;
        }
        len += BFS(v[order[v.size()-1]].first, v[order[v.size()-1]].second, ex, ey);
        ans = min(ans, len);
        return;
    }

    for(int i=0; i<v.size(); i++){
        if(check[i]) continue;
        check[i] = 1;
        order[cnt] = i;
        getOrder(i, cnt+1);
        check[i] = 0;
    }
}

int BFS(int ssx, int ssy, int eex, int eey){
    int nx, ny;
    memset(visitMap, 0, sizeof(visitMap));
    q.push(make_pair(0, make_pair(ssx, ssy)));
    visitMap[ssx][ssy] = 1;
    while(1) {
        pair<int, pair<int, int> > cur = q.front(); q.pop();
        if(cur.second.first == eex && cur.second.second == eey) {
            while(!q.empty()) q.pop();
            return cur.first;
        }
        for(int i=0; i<4; i++){
            nx = cur.second.first + dx[i];
            ny = cur.second.second + dy[i];
            if(nx < 1 || ny < 1 || nx > M || ny > N || map[nx][ny] == 1 || visitMap[nx][ny]) continue;
            visitMap[nx][ny] = 1;
            q.push(make_pair(cur.first+1, make_pair(nx, ny)));
        }
    }
}
