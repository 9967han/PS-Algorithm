#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
using namespace std;
void DFS(int x, int y, int low, int high);
int map[51][51], tired[51][51], visit[51][51];
int N;
set<int> s;
vector<int> v;
vector<pair<int, int> > dest;
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int main(){
    memset(map, 0, sizeof(map));
    cin >> N;
    int sx, sy;
    for(int i=1; i<=N; i++){
        string str;
        cin >> str;
        for(int j=0; j<N; j++){
            if(str[j] == 'P') {
                sx = i, sy = j+1;
            } else if(str[j] == 'K') {
                map[i][j+1] = 1;
                dest.push_back(make_pair(i, j+1));
            } 
        }
    }
    for(int i=1; i<=N; i++){ // set을 통해 오름차순 정렬 및 중복원소 제거
        for(int j=1; j<=N; j++) {
            cin >> tired[i][j];
            s.insert(tired[i][j]);
        }
    }
    for(set<int>::iterator iter=s.begin(); iter!=s.end(); iter++) {
        v.push_back(*iter); // 벡터에 옮겨담기
    }
    int st = 0, en = 0, ans = 987654321; // 투 포인터
    while(st <= en && en < v.size()) {
        memset(visit, 0, sizeof(visit));
        DFS(sx, sy, v[st], v[en]); // DFS
        bool flag = false;
        for(int i=0; i<dest.size(); i++){
            if(!visit[dest[i].first][dest[i].second]) { // 모든 집에 도달했는지 확인
                flag = true;
                break;
            }
        }
        if(flag){ // 도달하지 못한 경우
            en++;
        } else { // 도달한 경우
            ans = min(ans, v[en]-v[st]);
            st++;
        }
    }
    cout << ans;
    return 0;
}

void DFS(int x, int y, int low, int high){
    if(tired[x][y] > high || tired[x][y] < low) return;
    visit[x][y] = 1;
    for(int i=0; i<8; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 1 || ny < 1 || nx > N || ny > N || visit[nx][ny] || tired[nx][ny] > high || tired[nx][ny] < low) continue;
        DFS(nx, ny, low, high);
    }
    return;
}