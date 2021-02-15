#include<iostream>
#include<algorithm>
#include<cstring>
typedef long long ll;
#define mod 1000000007
ll solve(int S, int A, int B, int C);
using namespace std;
ll dp[51][51][51][51];
int main(){
    memset(dp, -1, sizeof(dp));
    int S, A, B, C;
    cin >> S >> A >> B >> C;
    cout << solve(S, A, B, C);
}

ll solve(int S, int A, int B, int C){
    if(S == 0) {
        if(A == 0 && B == 0 && C == 0) return 1;
        else return 0;
    }
    ll& ret = dp[S][A][B][C];
    if(ret != -1) return ret;
    ret = 0;
    ret += solve(S-1, A-1, B, C);
    ret += solve(S-1, A, B-1, C);
    ret += solve(S-1, A, B, C-1);
    ret += solve(S-1, A-1, B-1, C);
    ret += solve(S-1, A-1, B, C-1);
    ret += solve(S-1, A, B-1, C-1);
    ret += solve(S-1, A-1, B-1, C-1);
    ret %= mod;
    return ret;
}
