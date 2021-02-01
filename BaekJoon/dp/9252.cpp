#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;
string str1, str2;
int N, M, dp[1001][1001];
stack<char> s;
int main(){
    memset(dp, 0, sizeof(dp));
    cin >> str1 >> str2;
    N = str1.size();
    M = str2.size();
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[N][M] << '\n';
    while(N != 0 && M != 0){
        int cur = dp[N][M];
        if(cur == dp[N-1][M]){
            N--;
        } else if(cur == dp[N][M-1]){
            M--;
        } else if(cur == dp[N-1][M]+1 && cur == dp[N][M-1]+1){
            N--;
            M--;
            s.push(str1[N]);
        } 
    }
    while(!s.empty()){
        cout << s.top(); s.pop();
    }
    return 0;
}

