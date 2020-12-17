#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
long long arr[4001][4];
vector<long long> A, B;
int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            B.push_back(arr[i][2] + arr[j][3]);
        }
    }
    sort(B.begin(), B.end());
    long long ans = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int low = lower_bound(B.begin(), B.end(), -(arr[i][0]+arr[j][1])) - B.begin();
            int high = upper_bound(B.begin(), B.end(), -(arr[i][0]+arr[j][1])) - B.begin();
            ans += (high - low);
        }
    }
   cout << ans;
}
