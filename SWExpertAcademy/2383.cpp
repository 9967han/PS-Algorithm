#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
void getMinTime(int type, int cnt);
int getTime();
int T, N, ans=987654321;
int map[11][11], visit[10];
vector<pair<int, int> > person;
vector<pair<int, int> > stair;
vector<int> one, two;
int main(){
    cin >> T;
    for(int i=1; i<=T; i++){
        cin >> N;
        memset(visit, 0, sizeof(visit));
        person.clear(); stair.clear();
        ans = 987654321;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cin >> map[i][j];
                if(map[i][j] == 1) person.push_back(make_pair(i, j));
                if(map[i][j] > 1) stair.push_back(make_pair(i, j));
            }
        }
        cout << "#" << i << " ";
        getMinTime(0, 0);
        getMinTime(1, 0);
        cout << ans << endl;
    }
}

void getMinTime(int type, int cnt){  
    visit[cnt] = type;
    if(cnt == person.size()-1){
        one.clear(); two.clear();
        for(int i=0; i<person.size(); i++){
            if(visit[i]) {
                int px = person[i].first, py = person[i].second;
                int sx = stair[0].first, sy = stair[0].second;
                int dis = abs(px-sx) + abs(py-sy);
                one.push_back(dis+1);
            } else {
                int px = person[i].first, py = person[i].second;
                int sx = stair[1].first, sy = stair[1].second;
                int dis = abs(px-sx) + abs(py-sy);
                two.push_back(dis+1);
            }
        }
        sort(one.begin(), one.end());
        sort(two.begin(), two.end());
        ans = min(ans, getTime());
        return;
    }
    
    getMinTime(0, cnt+1);
    getMinTime(1, cnt+1);
}

int getTime(){
    int totalCnt = 0;
    queue<int> oneWaiting, twoWaiting;
    int oneStair[3] = {0, 0, 0}, twoStair[3] = {0, 0, 0};
    int oneIdx = 0, twoIdx = 0;
    for(int t=1; ; t++){
        for(int i=0; i<one.size(); i++) {
            if(one[i] == t){
                if(oneIdx == 3) oneWaiting.push(one[i]);
                else {
                    oneStair[oneIdx] = map[stair[0].first][stair[0].second]+1;
                    oneIdx++;
                }
            }
        }
        for(int i=0; i<two.size(); i++) {
            if(two[i] == t){
                if(twoIdx == 3) twoWaiting.push(two[i]);
                else {
                    twoStair[twoIdx] = map[stair[1].first][stair[1].second]+1;
                    twoIdx++;
                }
            }
        }

        int temp[3];
        memset(temp, 0, sizeof(temp));
        for(int i=0; i<3; i++){
            if(!oneStair[i]) continue;
            oneStair[i]--;
            if(!oneStair[i]) {
                oneIdx--;
                totalCnt++;
            }
        }
        for(int i=0, j=0; i<3; i++){
            if(oneStair[i]) {
                temp[j++] = oneStair[i];
            }
        }
        for(int i=0; i<3; i++){
            oneStair[i] = temp[i];
        }
        memset(temp, 0, sizeof(temp));

        for(int i=0; i<3; i++){
            if(!twoStair[i]) continue;
            twoStair[i]--;
            if(!twoStair[i]) {
                twoIdx--;
                totalCnt++;
            }
        }
        for(int i=0, j=0; i<3; i++){
            if(twoStair[i]) {
                temp[j++] = twoStair[i];
            }
        }
        for(int i=0; i<3; i++){
            twoStair[i] = temp[i];
        }
        memset(temp, 0, sizeof(temp));

        for(int i=oneIdx; i<=2 && !oneWaiting.empty(); i++){
            oneStair[i] = map[stair[0].first][stair[0].second];
            oneIdx++;
            oneWaiting.pop();
        }
        for(int i=twoIdx; i<=2 && !twoWaiting.empty(); i++){
            twoStair[i] = map[stair[1].first][stair[1].second];
            twoIdx++;
            twoWaiting.pop();
        }
        if(totalCnt == (one.size() + two.size())) return t;
    }
    return 0;
}