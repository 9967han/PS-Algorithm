#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;
bool isPossible(ll x);
ll T, q, d;
ll arr[10001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for(int t=1; t<=T; t++){
        cin >> q >> d;
        for(int i=1; i<=q; i++){
            cin >> arr[i];
            if(isPossible(arr[i])) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}

bool isPossible(ll x){
    ll temp = x;
    while(1){
        if(temp % 10 == d) {
            return true;
        }
        temp /= 10;
        if(temp == 0) break;
    }
    for(ll i=0; i*10<x; i++){
        if((x-10*i)%d == 0) return true;
    }
    return false;
}
