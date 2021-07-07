#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 9876543
using namespace std;
void printMap();
int map[101][101];
int N, M, st, en, cost;
int main(){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            map[i][j] = INF;
        }
    }
    printMap();
    for(int i=1; i<=M; i++){
        cin >> st >> en >> cost;
        map[st][en] = min(map[st][en], cost); 
    }
    printMap();
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    printMap();
}

void printMap(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}