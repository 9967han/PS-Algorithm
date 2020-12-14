#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
bool isCorrect(int x, int y, int k);
void DFS(int idx);
void printMap();
int map[10][10];
int ans = 0;
vector<pair<int, int> > v;
int main(){
    string str;
    for(int i=1; i<=9; i++){
        cin >> str;
        for(int j=0; j<9; j++){
            map[i][j+1] = str[j] - '0';
            if(map[i][j+1] == 0) v.push_back(make_pair(i, j+1));
        }
    }   
    DFS(0);
    return 0;
}

void DFS(int idx){
    if(idx == v.size()) {
        printMap();
        exit(0);
    }
    int x = v[idx].first, y = v[idx].second;
    for(int j=1; j<=9; j++){
        if(isCorrect(x, y, j)) {
            map[x][y] = j;
            DFS(idx+1);
            map[x][y] = 0;
        } 
    }
    return;
} 

bool isCorrect(int x, int y, int k){
    for(int i=1; i<=9; i++) {
        if(i == x) continue;
        if(map[i][y] == k) return false;
    }
    for(int i=1; i<=9; i++) {
        if(i == y) continue;
        if(map[x][i] == k) return false;
    }
    int tx, ty;
    if(x%3 == 0) tx = x/3;
    else tx = x/3+1;
    if(y%3 == 0) ty = y/3;
    else ty = y/3+1;
    tx *= 3, ty *= 3;
    for(int i=tx-2; i<=tx; i++){
        for(int j=ty-2; j<=ty; j++){
            if(i == x && j == y) continue;
            if(map[i][j] == k) return false;
        }
    }
    return true;
}



void printMap(){
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
}