#include<iostream>
#include<algorithm>
#include<cstring>
#define MIN -987654321
using namespace std;
int map[101][101];

int main(){
    int test_case = 1, N, res;
    while(1) {
        cin >> N;
        if(N == 0) break;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cin >> map[i][j];
            }
        }
        res = MIN;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(i+1 <= N && j+2 <= N) res = max(res, (map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+2]));//ㄱ
                if(i+2 <= N && j+1 <= N) res = max(res, (map[i+2][j] + map[i+2][j+1] + map[i+1][j+1] + map[i][j+1]));//j
                if(i+2 <= N && j+1 <= N) res = max(res, (map[i][j] + map[i+1][j] + map[i+2][j] + map[i][j+1]));//r
                if(i+1 <= N && j+2 <= N) res = max(res, (map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i+1][j+2]));//ㄴ
            }
        }
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(i+2 <= N && j+1 <= N) res = max(res, (map[i][j+1] + map[i+1][j] + map[i+1][j+1] + map[i+2][j]));//
                if(i+1 <= N && j+2 <= N) res = max(res, (map[i][j] + map[i+1][j+1] + map[i][j+1] + map[i+1][j+2]));//
            }
        }
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(i <= N && j+3 <= N) res = max(res, (map[i][j] + map[i][j+1] + map[i][j+2] + map[i][j+3]));//ㅡ
                if(i+3 <= N && j <= N) res = max(res, (map[i][j] + map[i+1][j] + map[i+2][j] + map[i+3][j]));//ㅣ
            }
        }
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(i+1 <= N && j+1 <= N) res = max(res, (map[i][j] + map[i+1][j] + map[i][j+1] + map[i+1][j+1]));//ㅁ
            }
        }
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(i+1 <= N && j+2 <= N) res = max(res, (map[i][j+1] + map[i+1][j] + map[i+1][j+1] + map[i+1][j+2]));//ㅗ
                if(i+1 <= N && j+2 <= N) res = max(res, (map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+1]));//ㅜ
                if(i+2 <= N && j+1 <= N) res = max(res, (map[i][j] + map[i+1][j] + map[i+2][j] + map[i+1][j+1]));//ㅏ
                if(i+2 <= N && j+1 <= N) res = max(res, (map[i][j+1] + map[i+1][j+1] + map[i+2][j+1] + map[i+1][j]));//ㅓ
            }
        }
        cout << test_case << ". " << res << '\n';
        test_case++;
    }
}