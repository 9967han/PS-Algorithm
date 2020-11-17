#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string getMin(string A, string B);
// 8 : 7개
// 0, 6, 9 : 6개
// 2, 3, 5 : 5개
// 4 : 4개
// 7 : 3개
// 1 : 2개
int T, N, M;
string dp[101];
int main(){
    cin >> T;
    for(int i=1; i<=T; i++){
        string bigNum="", smallNum="";
        cin >> N;
        M = N;
        if(N%2) {
            bigNum = "7";
            N -= 3;
        }
        while(N > 0) {
            N -= 2;
            bigNum += "1";
        }
        if(M < 10) {
            dp[2] = "1";
            dp[3] = "7";
            dp[4] = "4";
            dp[5] = "2";
            dp[6] = "6";
            dp[7] = "8";
            dp[8] = "10";
            dp[9] = "18";
        } else {
            for(int i=10; i<=100; i++) dp[i] = "999999999999999999999";
            for(int i=10; i<=100; i++){
                dp[i] = getMin(dp[i-2] + "1", dp[i]);
                dp[i] = getMin(dp[i-3] + "7", dp[i]);
                dp[i] = getMin(dp[i-4] + "4", dp[i]);
                dp[i] = getMin(dp[i-5] + "2", dp[i]);
                dp[i] = getMin(dp[i-6] + "0", dp[i]);
                dp[i] = getMin(dp[i-7] + "8", dp[i]);
            }
        }
        cout << dp[M] << " " << bigNum << endl;
    }
}

string getMin(string A, string B) {
    if(A.size() < B.size()) return A;
    else if(A.size() > B.size()) return B;
    else return min(A, B);
}