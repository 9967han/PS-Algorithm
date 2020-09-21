#include<iostream>
#include<algorithm>
using namespace std;
int map[301][301];
int N, M, R;
int main(){
    cin >> N >> M >> R;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> map[i][j];
        }
    }
    if(N >= M) {
        while(R) {
            for(int i=1; i<=M/2; i++){
                int temp = map[i][i];
                for(int j=i; j<=M-i+1; j++) map[i][j] = map[i][j+1];
                for(int j=i; j<=N-i+1; j++) map[j][M-i+1] = map[j+1][M-i+1];
                for(int j=M-i+1; j>i; j--) map[N-i+1][j] = map[N-i+1][j-1];
                for(int j=N-i+1; j>i; j--) map[j][i] = map[j-1][i];
                map[i+1][i] = temp;
            }
            R--;
        }
    } else {
        while(R) {
            for(int i=1; i<=N/2; i++){
                int temp = map[i][i];
                for(int j=i; j<=M-i+1; j++) map[i][j] = map[i][j+1];
                for(int j=i; j<=N-i+1; j++) map[j][M-i+1] = map[j+1][M-i+1];
                for(int j=M-i+1; j>i; j--) map[N-i+1][j] = map[N-i+1][j-1];
                for(int j=N-i+1; j>i; j--) map[j][i] = map[j-1][i];
                map[i+1][i] = temp;
            }
            R--;
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}