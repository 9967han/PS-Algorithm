#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, M, K;
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};
struct micros{
    int idx;
    int x;
    int y;
    int micNum;
    int dir;
    bool alive = true;
};
bool compare(micros A, micros B);
vector<micros> map[100][100], tempMap[100][100];
vector<micros> v;
int main(int argc, char** argv)
{
	int test_case, T, x, y, micNum, dir;
    cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        int ans = 0;
        cin >> N >> M >> K;
        v.clear();
        for(int i=1; i<=K; i++){
            cin >> x >> y >> micNum >> dir;
            micros mic; mic.idx = i-1; mic.x = x; mic.y = y; mic.micNum = micNum; mic.dir = dir; mic.alive = true;
            v.push_back(mic);
        }

        for(int t=1; t<=M; t++){
            for(int i=0; i<v.size(); i++){
                if(!v[i].alive) continue;
                int nx = v[i].x + dx[v[i].dir];
                int ny = v[i].y + dy[v[i].dir];
                if(nx == 0 || nx == N-1) {
                    v[i].dir = v[i].dir == 1 ? 2 : 1;
                    v[i].micNum = v[i].micNum / 2;
                    if(v[i].micNum == 0) v[i].alive = false;
                } else if(ny == 0 || ny == N-1) {
                    v[i].dir = v[i].dir == 3 ? 4 : 3;
                    v[i].micNum = v[i].micNum / 2;
                    if(v[i].micNum == 0) v[i].alive = false;
                }
                v[i].x = nx; v[i].y = ny;
                if(v[i].alive) map[nx][ny].push_back(v[i]);
                if(map[nx][ny].size() >= 2) sort(map[nx][ny].begin(), map[nx][ny].end(), compare);
            }

            for(int i=0; i<v.size(); i++){
                if(!v[i].alive) continue;
                int x = v[i].x, y = v[i].y; 
                if(map[x][y].size() >= 2) {
                    for(int k=1; k<map[x][y].size(); k++){
                        v[map[x][y][0].idx].micNum += v[map[x][y][k].idx].micNum;
                        v[map[x][y][k].idx].alive = false;
                    }
                }
                if(map[x][y].size() > 0) map[x][y].clear();
            }
        }
        for(int i=0; i<v.size(); i++) if(v[i].alive) ans += v[i].micNum;
        cout << "#" << test_case << " " << ans << endl;
	}
	return 0;
}

bool compare(micros A, micros B){
    return A.micNum > B.micNum;
}