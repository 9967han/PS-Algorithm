#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
void DFS(int idx, int cnt);
int getMinDiff();
int N, map[21][21], ans = 987654321;
int visit[21], selected[11], unselected[11];

int main(){
    memset(visit, 0, sizeof(visit));
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j];
        }
    }
    DFS(1, 1);
    cout << ans << endl;
}

void DFS(int idx, int cnt){
    if(cnt == N/2+1) {
        for(int i=1, j=1; i<=N; i++){
            if(!visit[i]) {
                unselected[j] = i;
                j++;
            }
        }
        ans = min(ans, getMinDiff());
        return;
    }

    for(int i=idx; i<=N; i++){
        if(visit[i]) continue;
        visit[i] = 1;
        selected[cnt] = i;
        DFS(i, cnt+1);
        visit[i] = 0;
    }
    return;
}

int getMinDiff(){
    int sumSel = 0, sumUnSel = 0;
    for(int i=1; i<=N/2; i++){
        for(int j=i+1; j<=N/2; j++){
            sumSel += map[selected[i]][selected[j]];
            sumSel += map[selected[j]][selected[i]];
            sumUnSel += map[unselected[i]][unselected[j]];
            sumUnSel += map[unselected[j]][unselected[i]];
        }
    }
    return abs(sumSel-sumUnSel);
}