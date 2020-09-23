#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int getMaxSize(int x, int y);
int map[21][21];
int T, N, M, ans=0;
int main(){
    cin >> T;
    for(int t=1; t<=T; t++){
        ans = 0;
        cin >> N >> M; 
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cin >> map[i][j];
            }
        }
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                ans = max(ans, getMaxSize(i, j));
            }
        }
        cout << "#" << t << " " << ans << endl;
    }
}

int getMaxSize(int x, int y){
    int res = 0;
    for(int k=1; k<=N+1; k++){
        int keepCost = k*k + (k-1)*(k-1);
        int income = 0;
        int homeCnt = 0;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if((abs(i-x) + abs(j-y) <= k-1) && map[i][j]){
                    homeCnt++;
                    income += M;
                }
            }
        }
        if(keepCost <= income) res = max(res, homeCnt);
    }
    return res;
}

