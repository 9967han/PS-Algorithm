#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
void catchShark(int y);
void moveShark();
void setMap();
struct shark{
    int x, y, s, d, z;
    bool die;
};
vector<shark> sharks;
int map[101][101];
int N, M, K, ans=0;
int main(){
    cin >> N >> M >> K;
    int r, c, s, d, z;
    for(int k=1; k<=K; k++){
        cin >> r >> c >> s >> d >> z;
        if(d == 1 || d == 2) s %= (2*N-2);
        if(d == 3 || d == 4) s %= (2*M-2);
        sharks.push_back({r, c, s, d, z, false});
    }
    for(int i=1; i<=M; i++){
        setMap();
        catchShark(i);
        moveShark();
    }
    cout << ans;
}

void setMap(){
    memset(map, 0, sizeof(map));
    for(int i=0; i<sharks.size(); i++){
        if(sharks[i].die) continue;
        int cx = sharks[i].x, cy = sharks[i].y;
        if(!map[cx][cy]) map[cx][cy] = sharks[i].z;
        else if(map[cx][cy] > sharks[i].z) sharks[i].die = true;
        else {
            for(int j=0; j<sharks.size(); j++) {
                if(sharks[j].die) continue;
                if(cx == sharks[j].x && cy == sharks[j].y && map[cx][cy] == sharks[j].z) {
                    sharks[j].die = true;
                    break;
                }
            }
            map[cx][cy] = sharks[i].z;
        }
    }
    return;
}

void moveShark(){ //d 1 2 3 4 : 위 아래 오른쪽 왼쪽
    for(int i=0; i<sharks.size(); i++){
        if(sharks[i].die) continue;
        int cx = sharks[i].x, cy = sharks[i].y;
        for(int j=1; j<=sharks[i].s; j++){
            if(sharks[i].d == 1) {
                cx--;
                if(cx < 1) {
                    cx = 2;
                    sharks[i].d = 2;
                }
            } else if(sharks[i].d == 2) {
                cx++;
                if(cx > N) {
                    cx = N-1;
                    sharks[i].d = 1;
                }
            } else if(sharks[i].d == 3) {
                cy++;
                if(cy > M) {
                    cy = M-1;
                    sharks[i].d = 4;
                }
            } else {
                cy--;
                if(cy < 1) {
                    cy = 2;
                    sharks[i].d = 3;
                }
            }
        }
        sharks[i].x = cx, sharks[i].y = cy;
    }
    return;
}

void catchShark(int y){
    for(int x=1; x<=N; x++){
        if(map[x][y]) {
            for(int j=0; j<sharks.size(); j++) {
                if(sharks[j].die) continue;
                if(sharks[j].x == x && sharks[j].y == y) {
                    sharks[j].die = true;
                    ans+=sharks[j].z;
                    return;
                }
            }
        }
    }
    return;
}