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
int map[11][11], nutrientMap[11][11], deathTreeMap[11][11];
vector<int> treeMap[11][11];
int main(){
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            map[i][j] = 5;
            cin >> nutrientMap[i][j]; // 영양소 맵에 받아두기
        }
    }
    int x, y, z;
    for(int i=1; i<=M; i++){
        cin >> x >> y >> z;
        treeMap[x][y].push_back(z); // 실제나무들은 트리맵 (벡터)
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
    memset(deathTreeMap, 0, sizeof(deathTreeMap)); //죽은 나무 맵 초기화
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(treeMap[i][j].size()) { // 나무가 있으면
                sort(treeMap[i][j].begin(), treeMap[i][j].end()); // 나이순 정렬
                vector<int> newTreeMap; // 살아남은 나무를 저장할 벡터
                for(int k=0; k<treeMap[i][j].size(); k++){
                    int treeAge = treeMap[i][j][k];
                    if(map[i][j] >= treeAge) { // 양분 >= 나이
                        map[i][j] -= treeAge;
                        newTreeMap.push_back(treeMap[i][j][k]+1); // 살아남은 나무에 추가
                    } else { // 양분 < 나이
                        deathTreeMap[i][j] += (treeAge/2); // 죽은 나무 맵에 추가
                    }
                }
                treeMap[i][j].clear();
                treeMap[i][j] = newTreeMap; // 해당 칸을 살아남은 나무 벡터로 변경 
            }
        }
    }
    return;
}

void summer(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            map[i][j] += deathTreeMap[i][j]; // 죽은 나무 맵 만큼 더해줌
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
                    for(int l=0; l<8; l++){ // 8방향으로 번식
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