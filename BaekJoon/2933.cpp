#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int getClusterHeight(int x, int y, int minHeight, int clusterNumber);
void moveCluster(int x, int clusterNumber);
void breakMineral(int x, int type);
void printMap();
void input();
int map[101][101], visit[101][101], cmd[101];
int N, M, K;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int main(){
    input();
    for(int i=1; i<=K; i++){
        breakMineral(N-cmd[i]+1, i%2);
        memset(visit, 0, sizeof(visit));
        int clusterNumber = 1;
        vector<pair<int, int> >mustMove;
        for(int j=1; j<=N; j++){
            for(int k=1; k<=M; k++){
                if(map[j][k] && !visit[j][k]) {
                    int isGround = getClusterHeight(j, k, 0, clusterNumber);
                    if(isGround != N) mustMove.push_back(make_pair(N-isGround, clusterNumber));// 땅에 붙어있지 않은것
                    clusterNumber++; //클러스터 넘버링
                }
            }
        }
        if(mustMove.size() > 0) moveCluster(mustMove[0].first, mustMove[0].second);// 땅에 붙어있지 않은 클러스터 N-isGround 만큼 내리기
    }
    printMap();
    return 0;
}

void moveCluster(int x, int clusterNumber){ // 클러스터 옮기기
    int temp[101][101];
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            temp[i][j] = map[i][j];
        }
    }
    for(int k=1; k<=x; k++){ //클러스터 별 최대 옮길 수 있는 거리 측정
        for(int i=N-1; i>=1; i--){
            for(int j=M; j>=1; j--){
                if((temp[i][j] == clusterNumber) && temp[i+1][j]) {
                    x = k-1;
                    break;
                }
                if(temp[i][j] == clusterNumber) {
                    temp[i+1][j] = temp[i][j];
                    temp[i][j] = 0;
                }
            }
        }
    }
    for(int i=N-x; i>=1; i--){ // 실제로 옮기기
        for(int j=M; j>=1; j--){
            if(map[i][j] == clusterNumber) {
                map[i+x][j] = map[i][j];
                map[i][j] = 0;
            }
        }
    }
    return;
}

int getClusterHeight(int x, int y, int minHeight, int clusterNumber){ // 클러스터별 넘버링해주기(DFS)
    visit[x][y] = 1;
    map[x][y] = clusterNumber;
    minHeight = max(minHeight, x);
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || ny < 1 || nx > N || ny > M || !map[nx][ny] || visit[nx][ny]) continue;
        minHeight = getClusterHeight(nx, ny, minHeight, clusterNumber);
    }
    return minHeight;
}

void breakMineral(int x, int type){ // 부수기
    if(type == 1) { // 왼쪽 -> 오른쪽 던짐
        for(int i=1; i<=M; i++){
            if(map[x][i]) {
                map[x][i] = 0; // 미네랄 깨기
                break;
            }
        }
    } else { // 오른쪽 -> 왼쪽 던짐
        for(int i=M; i>=1; i--){
            if(map[x][i]) {
                map[x][i] = 0; // 미네랄 깨기
                break;
            }
        }
    }
    return;
}

void input(){
    string str;
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> str;
        for(int j=1; j<=M; j++){
            if(str[j-1] == '.') map[i][j] = 0;
            else map[i][j] = 1;
        }
    }
    cin >> K;
    for(int i=1; i<=K; i++){
        cin >> cmd[i];
    }
    return;
}

void printMap(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(map[i][j]) cout << 'x';
            else cout << '.';
        }
        cout << endl;
    }
    return;
}