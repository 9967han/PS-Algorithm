#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
void DFS(int idx);
int N, M, visit[10000], arr[10000], score=0;
vector<int> v[10000];
int main(){
    memset(visit, 0, sizeof(visit));
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> arr[i];
    int x, y;
    for(int i=0; i<M; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=0; i<N; i++){
        if(!visit[i]) {
            DFS(i);
            if(score != 0) {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    cout << "POSSIBLE";
    return 0;
}

void DFS(int idx){
    visit[idx] = 1;
    score += arr[idx];
    for(int i=0; i<v[idx].size(); i++){
        if(!visit[v[idx][i]]) {
            DFS(v[idx][i]);
        }
    }
    return;
}