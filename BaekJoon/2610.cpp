#include<iostream>
#include<algorithm>
#include<vector>
#define INF 9999999
using namespace std;
int find(int x);
int N, M;
int dist[101][101], p[101], minDist[101], minPerson[101];
int main(){
    cin >> N >> M;
    int x, y;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            dist[i][j] = (i == j ? 0 : INF);
        }
        p[i] = i;
        minDist[i] = INF;
    }

    for(int i=1; i<=M; i++){
        cin >> x >> y;
        dist[x][y] = dist[y][x] = 1;
        int p1 = find(x), p2 = find(y);
        if(p1 != p2) p[p1] = p2;
    }

    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=1; i<=N; i++){
        int parent = find(i), dis = 0;
        for(int j=1; j<=N; j++){
            if(dist[i][j] != INF) dis = max(dis, dist[i][j]);
        }
        if(minDist[parent] > dis) {
            minDist[parent] = dis;
            minPerson[parent] = i;
        }
    }
    
    vector<int> ans;
    for(int i=1; i<=N; i++) {
        if(minPerson[i]) ans.push_back(minPerson[i]); 
    }

    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++) cout << ans[i] << endl;
    
    return 0;
}

int find(int x) {
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}