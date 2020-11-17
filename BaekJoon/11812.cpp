#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long N, x, y;
int K, Q;
int main(){
    cin >> N >> K >> Q;
    for(int i=1; i<=Q; i++){
        cin >> x >> y;
        int cnt = 0;
        if(K == 1) {
            cout << abs(x - y) << '\n';
            continue;
        }
        while(1){
            if(x > y) {
                x = (x-2) / K + 1;
                cnt++;
            }
            if(x == y) break;
            if(x < y) {
                y = (y-2) / K + 1;
                cnt++;
            }
            if(x == y) break;
        }
        cout << cnt << '\n';
    }
}
