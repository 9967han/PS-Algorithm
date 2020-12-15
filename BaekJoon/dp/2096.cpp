#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int N, temp[4], maxDp[4], minDp[4], arr[4];
int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[1] >> arr[2] >> arr[3];
        if(i == 1) {
            maxDp[1] = arr[1], maxDp[2] = arr[2], maxDp[3] = arr[3];
            minDp[1] = arr[1], minDp[2] = arr[2], minDp[3] = arr[3];
            continue;
        }
        temp[1] = max(maxDp[1], maxDp[2]) + arr[1];
        temp[2] = max(maxDp[1], maxDp[2]);
        temp[2] = max(temp[2], maxDp[3]) + arr[2];
        temp[3] = max(maxDp[2], maxDp[3]) + arr[3];
        maxDp[1] = temp[1], maxDp[2] = temp[2], maxDp[3] = temp[3];

        temp[1] = min(minDp[1], minDp[2]) + arr[1];
        temp[2] = min(minDp[1], minDp[2]);
        temp[2] = min(temp[2], minDp[3]) + arr[2];
        temp[3] = min(minDp[2], minDp[3]) + arr[3];
        minDp[1] = temp[1], minDp[2] = temp[2], minDp[3] = temp[3];
    }
    int maxRes = max(maxDp[1], maxDp[2]);
    maxRes = max(maxRes, maxDp[3]);
    int minRes = min(minDp[1], minDp[2]);
    minRes = min(minRes, minDp[3]);
    cout << maxRes << " " << minRes;
}