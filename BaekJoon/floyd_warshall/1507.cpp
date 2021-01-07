#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int N;
int map[21][21], edge[21][21];
int main(){
    memset(edge, -1, sizeof(edge));
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j];
        }
    }

    //플로이드-와샬 역으로 활용
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(i == k || k == j) continue;
                if(map[i][j] == map[i][k] + map[k][j]) edge[i][j] = 0;
                if(map[i][j] > map[i][k] + map[k][j]) {
                    cout << "-1";
                    return 0;
                }
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=N; i++){
        for(int j=i+1; j<=N; j++){
            if(edge[i][j]) ans+=map[i][j];
        }
    }
    cout << ans;
    return 0;
}