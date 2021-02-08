#include<iostream>
#include<algorithm>
#include<cmath>
typedef long long ll;
ll divide(ll X, ll Y);
using namespace std;
ll A, B, C, ans = 0;
int main(){
    cin >> A >> B >> C;
    cout << divide(A, B);
}

ll divide(ll X, ll Y){
    if(Y == 1) return X%C;
    ll res = 0;
    res = divide(X, Y/2);
    if(Y%2){ // 홀수
        return (res * res % C) * X % C;
    } else {
        return res * res % C;
    }
}