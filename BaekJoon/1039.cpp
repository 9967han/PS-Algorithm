#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
queue<pair<string, int> > q;
int visit[1000001][11];
int main(){
    string str;
    int K, ans=0;
    cin >> str >> K;
    q.push(make_pair(str, 0));
    memset(visit, 0, sizeof(visit));
    while(!q.empty()){
        pair<string, int> cur = q.front(); q.pop();
        if(cur.second == K) {
            ans = max(ans, stoi(cur.first));
            continue;
        }
        string curStr = cur.first;
        for(int i=0; i<curStr.size()-1; i++){
            for(int j=i+1; j<curStr.size(); j++){
                cout << curStr << endl;
                swap(curStr[i], curStr[j]);
                cout << curStr << endl;
                if(curStr[0] == '0') { // 맨앞이 0 이면 넘어가기
                    swap(curStr[i], curStr[j]);
                    continue;
                }
                if(visit[stoi(curStr)][cur.second+1]) continue; // 방문했던 노드면 넘어가기
                q.push(make_pair(curStr, cur.second+1)); 
                visit[stoi(curStr)][cur.second+1] = 1;
                swap(curStr[i], curStr[j]); // 백트랙
            }
        }
    }
    if(ans == 0) cout << "-1";
    else cout << ans;
}
