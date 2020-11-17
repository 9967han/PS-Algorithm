#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct horse{
    int x;
    int y;
    int mass;
    int s;
    int d;
};
vector<horse> map[51][51];
vector<horse> horses;
bool isDir(int x, int y);
void split();
void move();
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int N, M, K;

int main(){
    cin >> N >> M >> K;
    int x, y, mass, d, s, ans=0;
    for(int i=1; i<=M; i++){
        cin >> x >> y >> mass >> s >> d;
        horses.push_back({x, y, mass, s, d});
    }
    for(int i=1; i<=K; i++){
        move();
        split();
    }
    for(int i=0; i<horses.size(); i++) ans += horses[i].mass;
    cout << ans;
}

void move(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            map[i][j].clear();
        }
    }

    for(int i=0; i<horses.size(); i++){
        horse cur = horses[i];
        int cx = cur.x, cy = cur.y;
        int nx = cx+dx[cur.d]*cur.s, ny = cy+dy[cur.d]*cur.s;
        while(nx < 1) nx += N;
        while(ny < 1) ny += N;
        while(nx > N) nx -= N;
        while(ny > N) ny -= N;
        map[nx][ny].push_back({nx, ny, cur.mass, cur.s, cur.d});
    }
    return;
}

void split(){
    vector<horse> temp;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int massSum=0, sSum=0;
            if(map[i][j].size() == 0) continue;
            if(map[i][j].size() == 1) temp.push_back(map[i][j][0]);
            else {
                for(int k=0; k<map[i][j].size(); k++) {
                    massSum += map[i][j][k].mass;
                    sSum += map[i][j][k].s;
                }
                int nMass = massSum / 5;
                int nS = sSum / map[i][j].size();
                if(nMass == 0) continue;    
                if(isDir(i, j)) {
                    temp.push_back({i, j, nMass, nS, 0});
                    temp.push_back({i, j, nMass, nS, 2});
                    temp.push_back({i, j, nMass, nS, 4});
                    temp.push_back({i, j, nMass, nS, 6});
                } else {
                    temp.push_back({i, j, nMass, nS, 1});
                    temp.push_back({i, j, nMass, nS, 3});
                    temp.push_back({i, j, nMass, nS, 5});
                    temp.push_back({i, j, nMass, nS, 7});
                }
            }
        }
    }
    horses = temp;
}

bool isDir(int x, int y){
    bool evenFlag=false, oddFlag=false;
    for(int i=0; i<map[x][y].size(); i++){
        if(map[x][y][i].d % 2) oddFlag = true;
        else evenFlag = true;
    }
    if(evenFlag && !oddFlag) return true;
    else if(!evenFlag && oddFlag) return true;
    else return false;
}