#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;
bool isDivisible(ll x);
ll T, N;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for(int i=1; i<=T; i++){
        cin >> N;
        if(isDivisible(N)) cout << "YES\n";
        else cout << "NO\n";
    }
}

bool isDivisible(ll x){
    while(1){
        if(x!=1 && x%2) return true;
        if(x == 0) break;
        x = x/2;
    }
    return false;
}