#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
void spring();
void summer();
void fall();
void winter();
int N, M, K;
int tree[4][101], map[11][11], nutrientMap[11][11], deathTreeMap[11][11];
vector<int> treeMap[11][11];
int main(){
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            map[i][j] = 5;
            cin >> nutrientMap[i][j];
        }
    }
    int x, y, z;
    for(int i=1; i<=M; i++){
        cin >> x >> y >> z;
        treeMap[x][y].push_back(z);
    }
    for(int i=1; i<=K; i++){
        spring();
        summer();
        fall();
        winter();
    }
    int ans = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            ans += treeMap[i][j].size();
        }
    }
    cout << ans;
}

void spring(){
    memset(deathTreeMap, 0, sizeof(deathTreeMap));
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(treeMap[i][j].size()) {
                sort(treeMap[i][j].begin(), treeMap[i][j].end());
                vector<int> newTreeMap;
                for(int k=0; k<treeMap[i][j].size(); k++){
                    int treeAge = treeMap[i][j][k];
                    if(map[i][j] >= treeAge) {
                        map[i][j] -= treeAge;
                        newTreeMap.push_back(treeMap[i][j][k]+1);
                    } else {
                        deathTreeMap[i][j] += (treeAge/2);
                    }
                }
                treeMap[i][j].clear();
                treeMap[i][j] = newTreeMap;
            }
        }
    }
    return;
}

void summer(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            map[i][j] += deathTreeMap[i][j];
        }
    }
    return;
}

void fall(){
    int dx[] = {-1, 0, 0, 1, -1, -1, 1, 1};
    int dy[] = {0, -1, 1, 0, -1, 1, -1, 1};
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int k=0; k<treeMap[i][j].size(); k++){
                if(treeMap[i][j][k]%5 == 0) {
                    for(int l=0; l<8; l++){
                        int nx = i + dx[l];
                        int ny = j + dy[l];
                        if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
                        treeMap[nx][ny].push_back(1);
                    }
                }
            }
        }
    }
    return;
}

void winter(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            map[i][j] += nutrientMap[i][j];
        }
    }
    return;
}