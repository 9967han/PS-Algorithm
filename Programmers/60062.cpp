#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define INF 987654321
using namespace std;
void permute(int idx, int cnt);
bool compare(int A, int B) {
    return A > B;
}
vector<int> w, d;
int distlen, weaklen, visit[8], arr[8], answer=INF;
int solution(int n, vector<int> weak, vector<int> dist) {
    w = weak;
    for(int i=0; i<weak.size(); i++) w.push_back(weak[i]+n);
    d = dist;
    weaklen = w.size();
    distlen = dist.size();
    permute(0, 0);
    if(answer == INF) return -1;
    else return answer;
}

int getMin(int idx){
    int clearCnt = 0;
    for(int i=0; i<distlen; i++){
        int next = w[idx];
        int howfar = next + arr[i];
        while(howfar >= next){
            clearCnt++;
            idx++;
            next = w[idx];
            if(clearCnt == weaklen/2) return i+1;
        }
    }
    return INF;
}

void permute(int idx, int cnt){
    if(cnt == distlen) {
        for(int i=0; i<weaklen/2; i++) answer = min(answer, getMin(i));
        return;
    }
    for(int i=0; i<distlen; i++){
        if(visit[i]) continue;
        visit[i] = 1;
        arr[cnt] = d[i];
        permute(i, cnt+1);
        visit[i] = 0;
    }
}