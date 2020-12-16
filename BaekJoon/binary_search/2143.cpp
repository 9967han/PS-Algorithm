#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int T, N, M;
int A[1001], B[1001];
vector<int> sumA, sumB;

int main(){
    cin >> T >> N;
    for(int i=1; i<=N; i++) {
        cin >> A[i];
    }
    cin >> M;
    for(int i=1; i<=M; i++) {
        cin >> B[i];
    }
    for(int i=1; i<=N; i++){
        int sum = A[i];
        sumA.push_back(sum);
        for(int j=i+1; j<=N; j++){
            sum += A[j];
            sumA.push_back(sum);
        }
    }
    for(int i=1; i<=M; i++){
        int sum = B[i];
        sumB.push_back(sum);
        for(int j=i+1; j<=M; j++){
            sum += B[j];
            sumB.push_back(sum);
        }
    }

    long long ans = 0;
    sort(sumB.begin(), sumB.end());
    for(int i=0; i<sumA.size(); i++){
        int low = lower_bound(sumB.begin(), sumB.end(), T-sumA[i]) - sumB.begin();
        int high = upper_bound(sumB.begin(), sumB.end(), T-sumA[i]) - sumB.begin();
        ans += (high - low);
    }
    cout << ans;
    return 0;
}