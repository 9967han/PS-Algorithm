#include<iostream>
#include<algorithm>
using namespace std;
int N, H, a, ans=0;
int arr[1000001];
int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> a;
        if(arr[a+1]) {
            arr[a+1]--;
            arr[a]++;
        } else {
            arr[a]++;
            ans++;
        }
    } 
    cout << ans;
}