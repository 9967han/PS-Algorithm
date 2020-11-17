#include<iostream>
#include<algorithm>
using namespace std;
struct bottom{
    int num;
    int robot;
};
bottom map[201], temp[201];
int cnt=0, N, K, x;
int main(){
    cin >> N >> K;
    for(int i=1; i<=2*N; i++){
        cin >> map[i].num;
        map[i].robot = 0;
    }
    for(int t=1;;t++){
        //Step 1
        temp[1] = map[2*N];
        for(int i=2; i<=2*N; i++) temp[i] = map[i-1];
        for(int i=1; i<=2*N; i++) map[i] = temp[i];
        if(map[N].robot) map[N].robot = 0;
        
        //Step 2
        for(int i=N-1; i>=1; i--) {
            if(map[i].robot) {
                if(!map[i+1].robot && map[i+1].num >= 1) {
                    map[i+1].robot = map[i].robot;
                    map[i+1].num--;
                    if(map[i+1].num == 0) cnt++;
                    map[i].robot = 0;
                }
            }
        }
        if(map[N].robot) map[N].robot = 0;

        //Step 3
        if(map[1].num >= 1 && !map[1].robot) {
            map[1].robot = 1;
            map[1].num--;
            if(map[1].num == 0) cnt++;
        }

        //Step 4
        if(cnt >= K) {
            cout << t;
            return 0;
        }
    }
    return 0;
}

