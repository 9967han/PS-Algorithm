#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
vector<int> small[101], big[101];
void bigDFS(int bi, int sm);
void smallDFS(int sm, int bi);
int smallCnt[101], bigCnt[101], smallCheck[101], bigCheck[101];
int N, M, x, y, cnt=0, ans=0;
int main(){
    cin >> N >> M;
    for(int i=1; i<=M; i++){
        cin >> x >> y;
        small[y].push_back(x);
        big[x].push_back(y);
    }

    for(int i=1; i<=N; i++){
        memset(smallCheck, 0, sizeof(smallCheck));
        cnt = 0;
        for(int j=0; j<small[i].size(); j++) {
            if(!smallCheck[small[i][j]]) smallDFS(i, small[i][j]);
        }
        smallCnt[i] = cnt;
    }

    for(int i=1; i<=N; i++){
        memset(bigCheck, 0, sizeof(bigCheck));
        cnt = 0;
        for(int j=0; j<big[i].size(); j++) {
            if(!bigCheck[big[i][j]]) bigDFS(i, big[i][j]);
        }
        bigCnt[i] = cnt;
    }

    for(int i=1; i<=N; i++){
        if(smallCnt[i] >= (N/2+1) || bigCnt[i] >= (N/2+1)) ans++;
    }
    cout << ans;
    return 0;
}

void smallDFS(int sm, int bi){
    smallCheck[bi] = 1;
    cnt++;
    for(int i=0; i<small[bi].size(); i++){
        if(!smallCheck[small[bi][i]]) smallDFS(bi, small[bi][i]);
    }
    return;
}

void bigDFS(int bi, int sm){
    bigCheck[sm] = 1;
    cnt++;
    for(int i=0; i<big[sm].size(); i++){
        if(!bigCheck[big[sm][i]]) bigDFS(sm, big[sm][i]);
    }
    return;
}
