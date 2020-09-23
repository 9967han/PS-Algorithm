#include<iostream>
#include<algorithm>
using namespace std;
long long getNum(int w, int h);
long long dp[31][31];
int main(){
    int N;
    cin >> N;
    while(N){
        cout << getNum(N, 0) << '\n';
        cin >> N;
    }
}

long long getNum(int w, int h){
    if(w == 0 && h == 0) return 1; 
    if(dp[w][h]) return dp[w][h];
    if(w > 0) dp[w][h] += getNum(w-1, h+1);
    if(h > 0) dp[w][h] += getNum(w, h-1);
    return dp[w][h];
}
