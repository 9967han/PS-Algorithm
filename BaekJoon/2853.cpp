#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int N, num, ans=0, arr[5001], check[5001];
int main(){
    memset(arr, 0, sizeof(arr));
    memset(check, 0, sizeof(check));
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    for(int i=1; i<N; i++) {
        if(check[i]) continue;
        ans++;
        int d = arr[i]-1;
        int next = arr[i]+d;
        for(int j=i+1; j<N; j++) {
            if(next == arr[j]) {
                check[j] = 1;
                next+=d;
            }
        }
    }
    cout << ans;
}