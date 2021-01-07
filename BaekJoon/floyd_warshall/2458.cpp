#include<iostream>
#include<algorithm>
#define INF 987654321
using namespace std;
int N, M, st, en;
int small[501][501], big[501][501];
int main(){
    cin >> N >> M;   
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            small[i][j] = INF;
            big[i][j] = INF;
        }
    }
    for(int i=1; i<=M; i++){
        cin >> st >> en;
        small[st][en] = 1;
        big[en][st] = 1;
    }

    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                small[i][j] = min(small[i][j], small[i][k] + small[k][j]);
                big[i][j] = min(big[i][j], big[i][k] + big[k][j]);
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=N; i++){
        bool flag = false;
        for(int j=1; j<=N; j++){
            if(i == j) continue;
            if(small[i][j] == big[i][j] && big[i][j] == INF){
                flag = true;
                break;
            }
        }
        if(!flag) ans++;
    }
    cout << ans;
    
    return 0;
}