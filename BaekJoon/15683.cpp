#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void fill(int x, int y, int dir);
void unfill(int temp[9][9]);
void DFS(int cnt);
int countMap();
int N, M, map[9][9], ans = 0;
vector<pair<int, int> > v;
int main(){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> map[i][j];
            if(map[i][j] && map[i][j] != 6) v.push_back(make_pair(i, j));
            if(!map[i][j]) ans++;
        }
    }
    
	DFS(0);
    cout << ans << endl;
}

void DFS(int cnt) {
    if(cnt == v.size()) {
        ans = min(ans, countMap());
        return;
    }
    int temp[9][9];
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            temp[i][j] = map[i][j];
        }
    }

    int x = v[cnt].first, y = v[cnt].second;
    if(map[x][y] == 1) {
        for(int i=1; i<=4; i++) {
            fill(x, y, i);
            DFS(cnt+1);
            unfill(temp);
        }
    } else if(map[x][y] == 2) {
        fill(x, y, 1); fill(x, y, 2); // 동 서
        DFS(cnt+1);
        unfill(temp);

        fill(x, y, 3); fill(x, y, 4); // 남 북
        DFS(cnt+1);
        unfill(temp);
    } else if(map[x][y] == 3) {
        fill(x, y, 1); fill(x, y, 3); // 동 남
        DFS(cnt+1);
        unfill(temp);

        fill(x, y, 2); fill(x, y, 3); // 서 남
        DFS(cnt+1);
        unfill(temp);

        fill(x, y, 2); fill(x, y, 4); // 서 북
        DFS(cnt+1);
        unfill(temp);

        fill(x, y, 1); fill(x, y, 4); // 동 북
        DFS(cnt+1);
        unfill(temp);
    } else if(map[x][y] == 4) {
        fill(x, y, 1); fill(x, y, 2); fill(x, y, 3); // 동 서 남
        DFS(cnt+1);
        unfill(temp);

        fill(x, y, 1); fill(x, y, 2); fill(x, y, 4); // 동 서 북
        DFS(cnt+1);
        unfill(temp);

        fill(x, y, 1); fill(x, y, 3); fill(x, y, 4); // 동 남 북
        DFS(cnt+1);
        unfill(temp);

        fill(x, y, 2); fill(x, y, 3); fill(x, y, 4); // 서 남 북
        DFS(cnt+1);
        unfill(temp);
    } else {
        for(int i=1; i<=4; i++) fill(x, y, i); // 동 서 남 북
        DFS(cnt+1);
        unfill(temp);
    }
}

void fill(int x, int y, int dir) { // dir 1 2 3 4 동 서 남 북
    if(dir == 1) {
        for(int i=y+1; i<=M; i++) {
            if(map[x][i] == 6) break;
            else if(map[x][i]) continue;
            else map[x][i] = 9;
        }
    }
    if(dir == 2) {
        for(int i=y-1; i>=1; i--) {
            if(map[x][i] == 6) break;
            else if(map[x][i]) continue;
            else map[x][i] = 9;
        } 
    }
    if(dir == 3) {
        for(int i=x+1; i<=N; i++) {
            if(map[i][y] == 6) break;
            else if(map[i][y]) continue;
            else map[i][y] = 9;
        }
    }
    if(dir == 4){
        for(int i=x-1; i>=1; i--){
            if(map[i][y] == 6) break;
            else if(map[i][y]) continue;
            else map[i][y] = 9;
        }
    } 
    return;
}

void unfill(int temp[9][9]) {
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            map[i][j] = temp[i][j];
        }
    }
    return;
}

int countMap(){
    int res = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(!map[i][j]) res++;
        }
    }
    return res;
}