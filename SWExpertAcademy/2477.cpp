#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int getNum();
struct people{
    int idx;
    int meanTime;
};
int T, N, M, K, A, B;
int aTime[11], bTime[11], tk[1001];
int main(){
    cin >> T;
    for(int t=1; t<=T; t++){
        cin >> N >> M >> K >> A >> B;
        for(int i=1; i<=N; i++) cin >> aTime[i];
        for(int i=1; i<=M; i++) cin >> bTime[i];
        for(int i=1; i<=K; i++) cin >> tk[i];
        int res = getNum();
        cout << "#" << t << " ";
        cout << res << endl;   
    }
}

int getNum(){
    int ans = 0, finNum = 0;
    queue<int> q, q2;
    vector<pair<int, int> > res;
    vector<people> a[11], b[11];
    for(int i=1; i<=N; i++) a[i].push_back({0, 0});
    for(int i=1; i<=M; i++) b[i].push_back({0, 0});
    for(int i=1; i<=K; i++) res.push_back(make_pair(0, 0));
    int t = -1;
    while(finNum < K) {
        t++;
        for(int i=1; i<=K; i++){
            if(tk[i] == t) {
                q.push(i);
                tk[i] = -1;
            }
        }
        for(int i=1; i<=N; i++){
            if(a[i][0].meanTime == 0) {
                if(!q.empty()) {
                    a[i][0].idx = q.front();
                    a[i][0].meanTime = aTime[i]+1;
                    q.pop();
                } 
            } 
        }
        for(int i=1; i<=N; i++){
            if(a[i][0].meanTime == 0) continue;
            a[i][0].meanTime--;
            if(a[i][0].meanTime == 0) {
                q2.push(a[i][0].idx);
                res[a[i][0].idx].first = i;
                if(!q.empty()){
                    a[i][0].idx = q.front();
                    a[i][0].meanTime = aTime[i];
                    q.pop();
                }
            }
        }
        for(int i=1; i<=M; i++){
            if(b[i][0].meanTime == 0) {
                if(!q2.empty()){
                    b[i][0].idx = q2.front();
                    b[i][0].meanTime = bTime[i];
                    q2.pop();
                }
            }
        }
        for(int i=1; i<=M; i++){
            if(b[i][0].meanTime == 0) continue;
            b[i][0].meanTime--;
            if(b[i][0].meanTime == 0) {
                res[b[i][0].idx].second = i;
                b[i][0].idx = 0;
                finNum++; 
                if(!q2.empty()){
                    b[i][0].idx = q2.front();
                    b[i][0].meanTime = bTime[i];
                    q2.pop();
                }
            }
        }
        // cout << t << " : " << q.size() << " " << q2.size() << " " << finNum << endl;
        // if(q.size()) cout << q.front() << endl << endl;
    }
    for(int i=1; i<=K; i++){
        if(res[i].first == A && res[i].second == B) ans += i;
    }
    if(ans == 0) return 0;
    else return ans;
}
