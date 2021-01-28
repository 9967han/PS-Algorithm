#include<iostream>
#include<algorithm>
#include<cmath>
#define INF 987654321
using namespace std;
int N, arr[10003], ans=0;
int main(){
    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];
    arr[N+1] = 0, arr[N+2] = 0;
    for(int i=1; i<=N; i++){
        if(arr[i+1] > arr[i+2]){
            int temp = min(arr[i], arr[i+1]-arr[i+2]);
            arr[i] -= temp, arr[i+1] -= temp;
            ans += (temp*5);

            temp = min(arr[i], min(arr[i+1], arr[i+2]));
            arr[i] -= temp, arr[i+1] -= temp, arr[i+2] -= temp;
            ans += (temp*7);

            ans += arr[i]*3;
        } else {
            int temp = min(arr[i], min(arr[i+1], arr[i+2]));
            arr[i] -= temp, arr[i+1] -= temp, arr[i+2] -= temp;
            ans += (temp*7);

            temp = min(arr[i], arr[i+1]);
            arr[i] -= temp, arr[i+1] -= temp;
            ans += (temp*5);

            ans += arr[i]*3;
        }       
    }
    cout << ans;
}