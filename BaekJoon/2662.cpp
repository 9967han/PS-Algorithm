#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int N, M;
int arr[301][21]; // arr[n][m] : n원을 m번째 기업에 투자했을 경우 얻는 수익
int dp[301][21]; // dp[n][m] : n원으로 m번째회사까지 투자했을 때 얻는 최대수익
int invest[301][21]; // invest[n][m] : n원을 m번째 기업에 투자하기 
int main(){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=0; j<=M; j++){
            cin >> arr[i][j]; 
            
        }
    }
    
    for(int i=1; i<=M; i++){
        for(int j=1; j<=N; j++){
            for(int k=0; k<=j; k++){
                //k원을 i번째 회사에 투자 + j-k원을 i-1번째 회사까지 투자했을 때 얻는 최대수익
                if(dp[j][i] < arr[k][i] + dp[j-k][i-1]){
                    dp[j][i] = arr[k][i] + dp[j-k][i-1];
                    invest[j][i] = j-k;
                }
            }
        }
    }

    cout << dp[N][M] << endl;
    stack<int> s;
    for(int i=M; i>=1; i--){
        s.push(N - invest[N][i]);
        N = invest[N][i];
    }
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}

