#include<iostream>
#include<algorithm>
#include<cstring> 
#include<vector>
using namespace std;
void putBlockBlue(int x, int y, int t);
void putBlockGreen(int x, int y, int t);
void checkSpecialLine();
void pushGreenBlock();
void pushBlueBlock();
void checkLine();
void pushBlock();
void printMap();
void input();
int blue[4][6], green[6][4], type[10001], gScore=0, bScore=0;
int main(){
    input();
}

void input(){
    memset(blue, 0, sizeof(blue));
    memset(green, 0, sizeof(green));
    int N;
    cin >> N;
    int x, y, t;
    for(int i=1; i<=N; i++){
        cin >> t >> x >> y;
        type[i] = t;
        putBlockGreen(x, y, i);
        putBlockBlue(x, y, i);
        checkLine();
        checkSpecialLine();
        // printMap();
    }
    int score = 0;
    for(int i=0; i<6; i++){
        for(int j=0; j<4; j++){
            if(green[i][j]) score++;
            if(blue[j][i]) score++;
        }
    }
    cout << gScore + bScore << endl << score;
}

void checkSpecialLine(){
    int gCnt = 0, bCnt = 0;
    for(int i=0; i<2; i++){
        if(green[i][0] || green[i][1] || green[i][2] || green[i][3]) gCnt++;
        if(blue[0][i] || blue[1][i] || blue[2][i] || blue[3][i]) bCnt++;
    }
    if(gCnt){
        for(int i=5-gCnt; i>=0; i--){
            for(int j=0; j<4; j++){
                green[i+gCnt][j] = green[i][j];
            }   
        }
    } 
    if(bCnt){
        for(int i=5-bCnt; i>=0; i--){
            for(int j=0; j<4; j++){
                blue[j][i+bCnt] = blue[j][i];
            }
        }
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++){
            green[i][j] = 0;
            blue[j][i] = 0;
        }
    }
    return;
}

void checkLine(){
    bool gFlag = false, bFlag = false;
    for(int i=0; i<6; i++){
        if(green[i][0] != 0 && !green[i][0] == !green[i][1] && !green[i][1] == !green[i][2] && !green[i][2] == !green[i][3]) {
            green[i][0] = green[i][1] = green[i][2] = green[i][3] = 0;
            gScore++;
            gFlag = true;
        }
        if(blue[0][i] != 0 && !blue[0][i] == !blue[1][i] && !blue[1][i] == !blue[2][i] && !blue[2][i] == !blue[3][i]) {
            blue[0][i] = blue[1][i] = blue[2][i] = blue[3][i] = 0;
            bScore++;
            bFlag = true;
        }
    } 
    if(gFlag) pushGreenBlock();
    if(bFlag) pushBlueBlock();
    if(gFlag || bFlag) checkLine();
    return;
}

void pushBlueBlock() {
    for(int i=5; i>=0; i--){
        for(int j=0; j<4; j++){
            if(!blue[j][i]) continue;
            int idx = i;
            bool flag = false;
            int tmp = blue[j][i];
            if(type[blue[j][i]] == 3 && (j < 3 && blue[j+1][i] == blue[j][i])){
                blue[j][i] = 0, blue[j+1][i] = 0;
                while(idx <= 5) {
                    if(blue[j][idx] || blue[j+1][idx]) {
                        blue[j][idx-1] = tmp;
                        blue[j+1][idx-1] = tmp;
                        j++;
                        flag = true;
                        break;
                    }
                    idx++;
                }
                if(!flag) {
                    blue[j][5] = tmp;
                    blue[j+1][5] = tmp;
                }
            } else if(type[blue[j][i]] == 2 && (i < 5 && blue[j][i] == blue[j][i-1])){
                blue[j][i] = 0, blue[j][i-1] = 0;
                while(idx <= 5) {
                    if(blue[j][idx]) {
                        blue[j][idx-1] = tmp;
                        blue[j][idx-2] = tmp;
                        flag = true;
                        break;
                    }
                    idx++;
                }
                if(!flag) {
                    blue[j][5] = tmp;
                    blue[j][4] = tmp;
                }
            } else {
                blue[j][i] = 0;
                while(idx <= 5) {
                    if(blue[j][idx]) {
                        blue[j][idx-1] = tmp;
                        flag = true;
                        break;
                    }
                    idx++;
                }
                if(!flag) blue[j][5] = tmp;
            }
        }
    }
    return;
}

void pushGreenBlock(){
    for(int i=5; i>=0; i--){
        for(int j=0; j<4; j++){
            if(!green[i][j]) continue;
            int idx = i;
            bool flag = false;
            int tmp = green[i][j];
            if(type[green[i][j]] == 2 && (j < 3 && green[i][j+1] == green[i][j])){
                green[i][j] = 0, green[i][j+1] = 0;
                while(idx <= 5) {
                    if(green[idx][j] || green[idx][j+1]) {
                        green[idx-1][j] = tmp;
                        green[idx-1][j+1] = tmp;
                        j++;
                        flag = true;
                        break;
                    }
                    idx++;
                }
                if(!flag) {
                    green[5][j] = tmp;
                    green[5][j+1] = tmp;
                }
            } else if(type[green[i][j]] == 3 && (i < 5 && green[i][j] == green[i-1][j])){
                green[i][j] = 0, green[i-1][j] = 0;
                while(idx <= 5) {
                    if(green[idx][j]) {
                        green[idx-1][j] = tmp;
                        green[idx-2][j] = tmp;
                        flag = true;
                        break;
                    }
                    idx++;
                }
                if(!flag) {
                    green[5][j] = tmp;
                    green[4][j] = tmp;
                }
            } else {
                green[i][j] = 0;
                while(idx <= 5) {
                    if(green[idx][j]) {
                        green[idx-1][j] = tmp;
                        flag = true;
                        break;
                    }
                    idx++;
                }
                if(!flag) green[5][j] = tmp;
            }
        }
    }
    return;
}

void putBlockBlue(int x, int y, int t){
    bool flag = false;
    if(type[t] == 1) {
        for(int i=0; i<6; i++) {
            if(blue[x][i]) {
                flag = true;
                blue[x][i-1] = t;
                break;
            }
        }
        if(!flag) blue[x][5] = t;
    } else if(type[t] == 2) {
        for(int i=0; i<6; i++) {
            if(blue[x][i]) {
                flag = true;
                blue[x][i-1] = blue[x][i-2] = t;
                break;
            }
        }
        if(!flag) {
            blue[x][5] = blue[x][4] = t;
        }
    } else if(type[t] == 3) {
        for(int i=0; i<6; i++) {
            if(blue[x][i] || blue[x+1][i]) {
                flag = true;
                blue[x][i-1] = blue[x+1][i-1] = t;
                break;
            }
        }
        if(!flag) {
            blue[x][5] = blue[x+1][5] = t;
        }
    }
}

void putBlockGreen(int x, int y, int t){
    bool flag = false;
    if(type[t] == 1) {
        for(int i=0; i<6; i++) {
            if(green[i][y]) {
                flag = true;
                green[i-1][y] = t;
                break;
            }
        }
        if(!flag) green[5][y] = t;
    } else if(type[t] == 2) {
        for(int i=0; i<6; i++) {
            if(green[i][y] || green[i][y+1]) {
                flag = true;
                green[i-1][y] = green[i-1][y+1] = t;
                break;
            }
        }
        if(!flag) {
            green[5][y] = green[5][y+1] = t;
        }
    } else if(type[t] == 3) {
        for(int i=0; i<6; i++) {
            if(green[i][y]) {
                flag = true;
                green[i-1][y] = green[i-2][y] = t;
                break;
            }
        }
        if(!flag) {
            green[5][y] = green[4][y] = t;
        }
    }
}

void printMap(){
    cout << endl;
    cout << " - blue - " << endl;
    for(int i=0; i<4; i++){
        for(int j=0; j<6; j++){
            cout << blue[i][j] << " ";
        }
        cout << endl;
    }
    cout << " - green - " << endl;
    for(int i=0; i<6; i++){
        for(int j=0; j<4; j++){
            cout << green[i][j] << " ";
        }
        cout << endl;
    }
    return;
}