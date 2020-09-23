#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
unsigned long long ans = 0;
int main(){
    int A, B, C;
    cin >> A >> B >> C;
    ans = A % C;
    ans = pow(ans, B);
    cout << ans % C;
}