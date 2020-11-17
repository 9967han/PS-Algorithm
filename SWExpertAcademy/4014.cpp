#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int getPossibleNum(int map[21][21]);
int map[21][21], map2[21][21];
int T, N, X;
int main(){
    cin >> T;
    for(int t=1; t<=T; t++){
        cin >> N >> X;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cin >> map[i][j];
                map2[j][i] = map[i][j];
            }
        }
        cout << "#" << t << " " << getPossibleNum(map)+ getPossibleNum(map2) << endl;
        // getPossibleNum(map);
        // cout << "FIN" << endl;
        // getPossibleNum(map2);
    }
}

int getPossibleNum(int map[21][21]){
    int res = 0;
    for(int i=1; i<=N; i++){
        int before = map[i][1];
        int cnt = 1;
        bool flag = false;
        for(int j=2; j<=N; j++){
            if(abs(before-map[i][j]) >= 2) flag = true;
            else if(before == map[i][j]) {
                cnt++;
                continue;
            } else if(before > map[i][j]) {
                if(j+X > N+1) {
                    flag = true;
                    continue;
                }
                for(int k=j; k<=j+X-1; k++){
                    if(map[i][k] != map[i][j]) flag = true;
                }
                j = j+X-1;
                cnt = 0;
                before = map[i][j];
            } else if(before < map[i][j]) {
                if(cnt < X) flag = true;
                else {
                    cnt = 1;
                    before = map[i][j];
                }
            }
        }
        if(!flag) {
            res++;
            // cout << i << endl;
        }
    }
    return res;
}
