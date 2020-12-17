#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int getLower(double n);
long long X, Y, Z;
int main(){
    cin >> X >> Y;
    Z = (int)(Y*100/X);
    if(Z >= 99) {
        cout << "-1";
        return 0;
    }
    int st = 1, mid = 0, end = 1000000000, ans = 0;
    while(st <= end){
        mid = (st + end) / 2;
        if((int)((Y+mid)*100/(X+mid)) != Z){
            ans = mid;
            end = mid-1;
        } else {
            st = mid+1;
        }
    }
    cout << ans;
    return 0;
}