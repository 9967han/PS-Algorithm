#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool isFillable(int cnt, int type);
void fill(int cnt, int type);
void unfill(int cnt, int type);
void solve(int cnt, int fillCnt);
void printMap();
void input();
int map[13][13];
int N, coreCnt, ans = 987654321, ansCnt = 0;
vector<pair< int, int> > v;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        ans = 987654321, ansCnt = 0, coreCnt = 0;
        input();
        solve(1, 0);
        cout << "#" << test_case << " " << ans << '\n';
	}
	return 0;
}

void solve(int cnt, int fillCnt){
    if(cnt == coreCnt+1 && fillCnt >= ansCnt) { // 다 확인함
        if(fillCnt > ansCnt) {
            ans = 987654321;
            ansCnt = fillCnt;
        }
        int lineSum = 0;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(map[i][j]) lineSum++;
            }
        }
        lineSum -= coreCnt;
        if(ans > lineSum) {
            ans = lineSum;
            // printMap();
            // cout << "fillCnt : " << fillCnt << " ";
            // cout << ans << endl;
        }
        return;
    } 
    if(cnt == coreCnt+1) return;
    
    int checkFlag = false;
    for(int i=1; i<=4; i++){ // 1 : 상, 2 : 하, 3 : 좌, 4 : 우
        if(isFillable(cnt, i)){
            checkFlag = true;
            fill(cnt, i);
            solve(cnt+1, fillCnt+1);
            unfill(cnt, i);
        } 
    }
    if(!checkFlag) solve(cnt+1, fillCnt);
}

void input(){
    v.clear();
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j];
            if(map[i][j]) {
                v.push_back(make_pair(i, j));
                coreCnt++;
            }
        }
    }
    return;
}

void printMap(){
    for(int i=1; i<=N; i++){
        cout << endl;
        for(int j=1; j<=N; j++){
            cout << map[i][j] << " ";
        }
    }
    cout << endl;
    return;
}

bool isFillable(int cnt, int type){ // 1 : 상, 2 : 하, 3 : 좌, 4 : 우
    int x = v[cnt-1].first;
    int y = v[cnt-1].second;
    if((type == 1 && x == 1) || (type == 2 && x == N) || (type == 3 && y == 1)  || (type == 4 && y == N)) return true;
    if(type == 1) for(int i=x-1; i>=1; i--) if(map[i][y]) return false;
    if(type == 2) for(int i=x+1; i<=N; i++) if(map[i][y]) return false;
    if(type == 3) for(int i=y-1; i>=1; i--) if(map[x][i]) return false;
    if(type == 4) for(int i=y+1; i<=N; i++) if(map[x][i]) return false;
    return true;
}

void fill(int cnt, int type){
    int x = v[cnt-1].first;
    int y = v[cnt-1].second;
    if(type == 1) for(int i=x-1; i>=1; i--) map[i][y] = 2;
    if(type == 2) for(int i=x+1; i<=N; i++) map[i][y] = 2;
    if(type == 3) for(int i=y-1; i>=1; i--) map[x][i] = 2;
    if(type == 4) for(int i=y+1; i<=N; i++) map[x][i] = 2;
    return;
}

void unfill(int cnt, int type){
    int x = v[cnt-1].first;
    int y = v[cnt-1].second;
    if(type == 1) for(int i=x-1; i>=1; i--) map[i][y] = 0;
    if(type == 2) for(int i=x+1; i<=N; i++) map[i][y] = 0;
    if(type == 3) for(int i=y-1; i>=1; i--) map[x][i] = 0;
    if(type == 4) for(int i=y+1; i<=N; i++) map[x][i] = 0;
    return;
}