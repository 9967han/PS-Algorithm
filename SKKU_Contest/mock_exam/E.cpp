#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int N, M, sum=0, arr[11], dp[100001][11];
int main(){
    memset(dp, -1, sizeof(dp));
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
        sum += (arr[i]*arr[i]);
    }
    dp[sum][0] = 0;
    for(int i=1; i<=N; i++){
        for(int k=1; k<100; k++){
            if(arr[i] > k) { // 줄이는 경우
                int price = (arr[i]-k) * (arr[i]-k);
                int diff = (arr[i]*arr[i] - k*k);
                if(price > 100000) continue;
                for(int j=0; j<=100000; j++){
                    if(dp[j][i-1] == -1 || j-diff < 0) continue;
                    if(i == 1) dp[j-diff][1] = price;
                    else if(dp[j-diff][i] != -1) dp[j-diff][i] = min(dp[j-diff][i], dp[j][i-1] + price); // 이미 있었
                    else dp[j-diff][i] = dp[j][i-1] + price; // 한번도 없었
                }
            } else { // 늘리는 경우
                int price = (k-arr[i]) * (k-arr[i]);
                int diff = (k*k - arr[i]*arr[i]);
                if(price > 100000) continue;
                for(int j=0; j<=100000; j++){
                    if(dp[j][i-1] == -1 || j+diff > 10000) continue;
                    if(i == 1) dp[j+diff][1] = price;
                    else if(dp[j+diff][i] != -1) dp[j+diff][i] = min(dp[j+diff][i], dp[j][i-1] + price);
                    else dp[j+diff][i] = dp[j][i-1] + price;
                }
            }
        }
    }
    cout << dp[M][N];
}