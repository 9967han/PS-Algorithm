#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
int getMaxBoggle(string cur, int x, int y);
int getScore(string str);
void solution();
void input();
vector<string> words;
string map[4];
int visit[300000], visitMap[4][4];
int dx[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dy[] = {0, -1, 1, 0, -1, 1, -1, 1};
int w, b, maxScore=0, findNum=0;
string maxString = "";

int main(){
    input();
}

void input(){
    cin >> w;
    for(int i=0; i<w; i++) {
        string str;
        cin >> str;
        words.push_back(str);
    }
    sort(words.begin(), words.end());
    cin >> b;
    for(int i=0; i<b; i++){
        for(int j=0; j<4; j++) cin >> map[j];

        //init
        maxScore = 0, findNum = 0;
        maxString = "";
        memset(visit, 0, sizeof(visit));
        solution();
        cout << maxScore << " " << maxString << " " << findNum << endl;
    }
    return;
}

void solution(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            visitMap[i][j] = 1;
            getMaxBoggle(string(1, map[i][j]), i, j);
            visitMap[i][j] = 0;
        }
    }
    return;
}

int getMaxBoggle(string cur, int x, int y){
    if(cur.size() >= 9) return 0;
    if(cur.size() >= 3) {
        for(int i=0; i<w; i++) {
            if(visit[i]) continue;
            if(words[i] == cur) {
                visit[i] = 1;
                maxScore += getScore(words[i]);
                if(cur.size() > maxString.size()) maxString = cur;
                findNum++;
            }
        }
    }
    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx > 3 || ny > 3 || visitMap[nx][ny]) continue;
        visitMap[nx][ny] = 1;
        getMaxBoggle(cur + map[nx][ny], nx, ny);
        visitMap[nx][ny] = 0;
    }
    return 0;
}

int getScore(string str){
    if(str.size() == 3 || str.size() == 4) return 1;
    else if(str.size() == 5) return 2;
    else if(str.size() == 6) return 3;
    else if(str.size() == 7) return 5;
    else if(str.size() == 8) return 11;
    else return 0;
}