#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int getPath(int fx, int fy, int sx, int sy);
int N, M, A, B;
int map[101][101];
int dp[101][101]; 
vector<pair<int, int> > v;
int main(){
    memset(map, 0, sizeof(map));
    memset(dp, 0, sizeof(dp));
    cin >> N >> M >> A >> B;
    int x, y;
    v.push_back(make_pair(1, 1));
    for(int i=1; i<=A; i++){
        cin >> x >> y;
        map[x][y] = 1;
        v.push_back(make_pair(x, y));
    }
    v.push_back(make_pair(N, M));
    sort(v.begin(), v.end());
    for(int i=1; i<=B; i++){
        cin >> x >> y;
        map[x][y] = 2;
    }
    int ans = 1;
    for(int i=0; i<v.size()-1; i++){
        ans *= getPath(v[i].first, v[i].second, v[i+1].first, v[i+1].second);
    }
    cout << ans;
    return 0;
}
int getPath(int fx, int fy, int sx, int sy){
    dp[fx][fy] = 1;
    for(int i=fx; i<=sx; i++){
        for(int j=fy; j<=sy; j++){
            if(i==fx && j==fy) continue;
            if(map[i][j] == 2) dp[i][j] = 0;
            else dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    return dp[sx][sy];
}