#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
vector<int> link, start;
void DFS(int idx, int cnt);
int map[21][21], visit[21];
int N, ans = 987654321;
int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j];
        }
    }
    DFS(1, 1);
    cout << ans;
}

void DFS(int idx, int cnt){
    if(cnt == N/2+1) {
        link.clear();
        start.clear();
        for(int i=1; i<=N; i++) {
            if(visit[i]) link.push_back(i);
            else start.push_back(i);
        }
        int linkSum = 0, startSum = 0;
        for(int i=0; i<link.size(); i++){
            for(int j=i+1; j<link.size(); j++){
                linkSum += map[link[i]][link[j]];
                linkSum += map[link[j]][link[i]];
            }
        }
        for(int i=0; i<start.size(); i++){
            for(int j=i+1; j<start.size(); j++){
                startSum += map[start[i]][start[j]];
                startSum += map[start[j]][start[i]];
            }
        }
        ans = min(ans, abs(linkSum-startSum));
        return;
    }   

    for(int i=idx; i<=N; i++){
        if(!visit[i]) {
            visit[i] = 1;
            DFS(i, cnt+1);
            visit[i] = 0;
        }
    }
}