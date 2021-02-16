#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int N, res = 0, map[51][51];
void _swap(int x, int y, int nx, int ny);
void printMap();
int check();
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int main(){
    string str;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> str;
        for(int j=1; j<=N; j++){
            if(str[j-1] == 'Y') map[i][j] = 1;
            if(str[j-1] == 'C') map[i][j] = 2;
            if(str[j-1] == 'P') map[i][j] = 3;
            if(str[j-1] == 'Z') map[i][j] = 4;
        }
    }
    check();
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int k=0; k<4; k++){
                int nx = i + dx[k], ny = j + dy[k];
                if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
                _swap(i, j, nx, ny);
                check();
                _swap(i, j, nx, ny);
            }
        }
    }
    cout << res;
    return 0;
}

void _swap(int x, int y, int nx, int ny){
    int temp = map[nx][ny];
    map[nx][ny] = map[x][y];
    map[x][y] = temp;
    return;
}

int check(){
    for(int i=1; i<=N; i++){
        int cnt = 1;
        int cur = map[i][1];
        for(int j=2; j<=N; j++){
            if(cur == map[i][j]) {
                cnt++;
                res = max(res, cnt);
            } else {
                cnt = 1;
                cur = map[i][j];
            }
        }
    }
    for(int i=1; i<=N; i++){
        int cnt = 1;
        int cur = map[1][i];
        for(int j=2; j<=N; j++){
            if(cur == map[j][i]) {
                cnt++;
                res = max(res, cnt);
            } else {
                cnt = 1;
                cur = map[j][i];
            }
        }
    }
    return res;
}

void printMap(){
    cout << endl;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    return;
}