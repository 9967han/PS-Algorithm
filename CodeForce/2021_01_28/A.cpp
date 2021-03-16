#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int T, N, arr[101], visit[101], ans = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for(int t=1; t<=T; t++){
        ans = 0;
        memset(arr, 0, sizeof(arr));
        memset(visit, 0, sizeof(visit));
        cin >> N;
        for(int i=1; i<=N; i++){
            cin >> arr[i];
        }
        for(int i=1; i<=N; i++){
            if(visit[i]) continue;
            ans++;
            int cur = arr[i];
            for(int j=i+1; j<=N; j++){
                if(visit[j]) continue;
                if(cur < arr[j]) {
                    cur = arr[j];
                    visit[j] = 1;
                }
            }
        }
        cout << ans << '\n';
    }
}