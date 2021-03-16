#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int T, N, arr[1000001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    memset(arr, 0, sizeof(arr));
    for(int i=0; i<=500; i++){
        for(int j=0; j<=500; j++){
            int n = 2020*i + 2021*j;
            if(n <= 1000000) arr[n] = 1;
        }
    }
    for(int i=1; i<=T; i++){
        cin >> N;
        if(arr[N]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}