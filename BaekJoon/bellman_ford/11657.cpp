#include<iostream>
#include<algorithm>
#include<vector>
#define INF 987654321
using namespace std;
int N, M, st, en, cost;
long long dist[501], temp[501];
vector<vector<pair<int, int> > > edge;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    edge.resize(N+1);
    for(int i=2; i<=N; i++) dist[i] = INF;
    dist[1] = 0;
    for(int i=1; i<=M; i++){
        cin >> st >> en >> cost;
        edge[st].push_back(make_pair(en, cost));
    }

    for(int n=1; n<=N; n++){
        for(int i=1; i<=N; i++){
            if(dist[i] == INF) continue;
            for(int j=0; j<edge[i].size(); j++){
                en = edge[i][j].first;
                cost = edge[i][j].second;
                dist[en] = min(dist[en], dist[i] + cost);
            }
        }
    }
    
    for(int i=1; i<=N; i++) temp[i] = dist[i];
    for(int i=1; i<=N; i++){
        if(temp[i] == INF) continue;
        for(int j=0; j<edge[i].size(); j++){
            en = edge[i][j].first;
            cost = edge[i][j].second;
            temp[en] = min(temp[en], temp[i] + cost);
        }
    }

    for(int i=1; i<=N; i++){
        if(temp[i] != dist[i]) {
            cout << "-1";
            return 0;
        }
    }

    for(int i=2; i<=N; i++) {
        if(dist[i] == INF) cout << "-1\n";
        else cout << dist[i] << '\n';
    }
}