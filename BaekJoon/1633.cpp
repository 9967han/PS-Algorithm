#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cstring>
using namespace std;
int DFS(int idx, int wh, int bl);
int arr[1001][2], dp[1001][16][16], N=1;
int main(){
    memset(dp, 0, sizeof(dp));
    int a, b;
    while( scanf("%d %d", &a, &b) == 2) {
        arr[N][0] = a;
        arr[N][1] = b;
        N++;
    }
    cout << DFS(0, 0, 0);
    return 0;
}

int DFS(int idx, int wh, int bl) {
    if(wh == 15 && bl == 15) return 0;
    if(idx == N) return 0;
    if(dp[idx][wh][bl]) return dp[idx][wh][bl];
    int ans = 0;
    if(wh < 15) ans = max(ans, DFS(idx+1, wh+1, bl) + arr[idx+1][0]);
    if(bl < 15) ans = max(ans, DFS(idx+1, wh, bl+1) + arr[idx+1][1]);
    return dp[idx][wh][bl] = max(ans, DFS(idx+1, wh, bl));
}