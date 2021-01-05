#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a, b, c, d;
int main(){
    cin >> a >> b >> c >> d;
    if(a < b && b < c && c < d) cout << "Uphill";
    else if(a > b && b > c && c > d) cout << "Downhill";
    else if(a == b && b == c && c == d) cout << "Flat Land";
    else cout << "Unknown";
    return 0;
}